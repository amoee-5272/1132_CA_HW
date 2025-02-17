import subprocess
import re

import os
import zipfile
import csv

# ================== Testbench Script ==================
# Put this file in the same folder as the Ripes.exe
# Modify the filename and input to test the script
# ======================================================



def T(n): # Calculate global answer
    # Base cases
    if n == 0:
        return 4
    # Recursive case
    return 4 * T((n - 1) >> 1) + 8 * n + 3

def grade_script_p1(command, correct_answer):
    try:
        
        result = subprocess.run(command, shell=True, capture_output=True, text=True)
        output = result.stdout
        print(output)
        
        # find match
        match = re.search(r"x10:\s+(\d+)", output)
        
        if match:
            student_answer = int(match.group(1))  # catch answer
            if student_answer == correct_answer:
                # return f"Correct! The answer is {student_answer}."
                return 10
            else:
                return 0
                # return f"Incorrect. Your answer: {student_answer}, Expected answer: {correct_answer}."
        else:
            return "Error: Could not find a line matching the format 'Result is ?' in the output."

    except Exception as e:
        return str(e)
        # return f"An error occurred: {str(e)}"


def replace_line_in_file_p1(filename, new_content):
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
        if "input: .word" in line:
            lines[i] = new_content + '\n'  # 替換為新內容
            modified = True
            break

    if not modified:
        print(f"No line containing 'input: .word' found in '{filename}'.")
        return

    # 將修改後的內容寫回檔案
    with open(filename, 'w') as file:
        file.writelines(lines)

    print(f"Updated '{filename}' successfully.")


def grade_hw1_1(file_path):
    input = [7, 10, 30, 57, 63, 81, 98, 100, 121, 150]
    score = 0
    for n in input:
        new_content = f"input: .word {input}"  # replace content
        replace_line_in_file_p1(filename, new_content)
        command_to_run = f"Ripes.exe --mode cli --src {filename} -t asm --proc RV32_5S --regs"  
        correct_answer = T(input)  # correct answer
        score += grade_script_p1(command_to_run, correct_answer)
    return score  

def grade_hw1_2(file_path):
    return 0 



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
            hw1_2_path = os.path.join(extracted_folder, "hw1_2.s")
            
            score_hw1_1 = grade_hw1_1(hw1_1_path)
            score_hw1_2 = grade_hw1_2(hw1_2_path)
            
            results.append([student_id, score_hw1_1, score_hw1_2])
    
    with open("homework_results.csv", 'w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(["Student ID", "HW1_1 Score", "HW1_2 Score"])
        


# example usage
if __name__ == "__main__":
    homework_directory = "/path/to/your/homework"
    process_homework_directory(homework_directory)
