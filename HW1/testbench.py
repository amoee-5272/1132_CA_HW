import subprocess
import re

import os
import zipfile
import csv

# ================== Testbench Script ==================
# Put this file in the same folder as the Ripes.exe
# Modify the filename and input to test the script
# ======================================================

# 計算最長遞增子序列的 function
def longest_increasing_subsequence(sequence):
    if not sequence:
        return 0

    # dp array to store the length of the LIS ending at each index
    dp = [1] * len(sequence)

    # Calculate the LIS for each element
    for i in range(1, len(sequence)):
        for j in range(i):
            if sequence[i] > sequence[j]:
                dp[i] = max(dp[i], dp[j] + 1)

    # The length of the LIS is the maximum value in the dp array
    return max(dp)


def T(n): # Calculate global answer
    # Base cases
    if n == 0:
        return 4
    # Recursive case
    return 4 * T((n - 1) >> 1) + 8 * n + 3

def grade_script_p1(command, correct_answer):
    res=""
    try:
        
        result = subprocess.run(command, shell=True, capture_output=True, text=True)
        output = result.stdout
        print(output)
        
        # find match
        match = re.search(r"x10:\s+(\d+)", output)
        
        if match:
            student_answer = int(match.group(1))  # catch answer
            if student_answer == correct_answer:
                return 10 , res
            else:
                res +=  f"Incorrect. Your answer: {student_answer}, Expected answer: {correct_answer}."
                return 0 , res
                # return f"Incorrect. Your answer: {student_answer}, Expected answer: {correct_answer}."
        else:
            return "Error: Could not find a line matching the format in the output."

    except Exception as e:
        return str(e)
        # return f"An error occurred: {str(e)}"


def replace_line_in_file(filename,old_content, new_content):
    # 確認檔案存在
    try:
        with open(filename, 'r') as file:
            lines = file.readlines()
    except FileNotFoundError:
        print(f"Error: File '{filename}' not found.")
        return

    # 找到包含 "input: .word" 的行並替換
    modified = False
    for i, line in enumerate(lines):
        if old_content in line:
            lines[i] = new_content + '\n'  # 替換為新內容
            modified = True
            break

    if not modified:
        print(f"No line containing '{old_content}' found in '{filename}'.")
        return

    # 將修改後的內容寫回檔案
    with open(filename, 'w') as file:
        file.writelines(lines)

    print(f"Updated '{filename}' successfully.")



def grade_hw1_1(file_path):
    input = [7, 57, 121, 150, 398]
    score = 0
    for n in input:
        old_content = "input: .word"  # old content
        new_content = f"input: .word {n}"  # replace content
        replace_line_in_file(file_path, old_content, new_content)
        command_to_run = f"Ripes.exe --mode cli --src {file_path} -t asm --proc RV32_5S --regs"  
        correct_answer = T(n)  # correct answer
        score += grade_script_p1(command_to_run, correct_answer)[0]
    return score  

def grade_hw1_2(file_path):
    input1 = [4, 5, 1, 8, 3, 6, 9 ,2]
    input2 = [4, 89, 58, 94, 7, 98, 60, 73, 90, 91, 43, 24, 48, 25, 50, 12, 71, 48, 45, 74, 88, 73, 13, 72, 37, 14, 69]
    input3 = [82, 38, 6, 2, 8, 75, 80, 22, 67, 11, 12, 25, 72, 80, 35, 81, 66, 68, 28, 87, 25, 14, 4, 13, 59, 28, 34, 61, 28, 96, 99, 52, 54, 37]
    input4 = [47, 8, 64, 56, 70, 23, 79, 16, 20, 10, 56, 29, 38, 89, 50, 99, 66, 45, 63, 43, 99, 75]
    input5 = [27, 2, 81, 68, 56, 59, 75, 43, 39, 93, 34, 46, 83, 52, 78, 34, 33, 41, 69, 89, 1, 4, 31, 3, 76, 51, 58, 77, 74, 46, 58, 39, 88, 79, 46, 22, 82, 78, 38, 57, 18, 71, 77, 52, 54, 37, 43, 81]
    inputs = [input1,input2,input3,input4,input5]
    score = 0
    res = ""
    for input in inputs:
        
        old_line = "nums:"
        new_line = "nums:   .word " + ", ".join(map(str, input))    
        replace_line_in_file(file_path, old_line, new_line)

        old_line = "n:"
        new_line = "n:   .word " + str(len(input))
        replace_line_in_file(file_path, old_line, new_line)

        old_line = "dp:"
        new_line = "dp:   .word " + ", ".join(["0"] * len(input))
        replace_line_in_file(file_path, old_line, new_line)

        command_to_run = f"Ripes.exe --mode cli --src {file_path} -t asm --proc RV32_5S --regs"  
        answer = longest_increasing_subsequence(input)
        score += grade_script_p1(command_to_run, answer)[0]
        res += grade_script_p1(command_to_run, answer)[1]

    print(res)
    print("p2_score= ",score)
    return score



def process_homework_directory(directory_path):
    results = []
    
    for item in os.listdir(directory_path):
        if item.endswith("_hw1.zip"):
            student_id = item.split("_")[0]
            zip_path = os.path.join(directory_path, item)
            
            with zipfile.ZipFile(zip_path, 'r') as zip_ref:
                zip_ref.extractall(directory_path)
            
            extracted_folder = os.path.join(directory_path, f"{student_id}_hw1")
            hw1_1_path = os.path.join(extracted_folder, "hw1_1.s")
            print(hw1_1_path)
            hw1_2_path = os.path.join(extracted_folder, "hw1_2.s")
            
            score_hw1_1 = grade_hw1_1(hw1_1_path)
            print(score_hw1_1)
            score_hw1_2 = grade_hw1_2(hw1_2_path)
            
            results.append([student_id, score_hw1_1, score_hw1_2])
    
    with open("homework_results.csv", 'w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(["Student ID", "HW1_1 Score", "HW1_2 Score"])
        writer.writerows(results)
        


# example usage
if __name__ == "__main__":
    homework_directory = "./homework"
    process_homework_directory(homework_directory)
