import subprocess
import re

def T(n):
    # Base cases
    if n == 0:
        return 4
    # Recursive case
    return 4 * T((n - 1) >> 1) + 8 * n + 3

def grade_script(command, correct_answer):
    try:
        
        result = subprocess.run(command, shell=True, capture_output=True, text=True)
        # print(result)
        # get output
        output = result.stdout
        print(output)
        
        # find match
        match = re.search(r"Result is (\d+)", output)
        
        if match:
            student_answer = int(match.group(1))  # catch answer
            if student_answer == correct_answer:
                return "==== Correct ^^ ===="
                # return f"Correct! The answer is {student_answer}. Full score awarded."
            else:
                return "==== incorrect !! ===="
                # return f"Incorrect. Your answer: {student_answer}, Expected answer: {correct_answer}."
        else:
            return "Error: Could not find a line matching the format 'Result is ?' in the output."

    except Exception as e:
        return str(e)
        # return f"An error occurred: {str(e)}"


def replace_line_in_file(filename, new_content):
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





# example usage
if __name__ == "__main__":
    # set command here
    filename = "hw1/hw1_sol_v1.s"  # file name
    input = 20  # input
    new_content = f"input: .word {input}"  # replace content
    replace_line_in_file(filename, new_content)

    command_to_run = f"Ripes.exe --mode cli --src {filename} -t asm --proc RV64_5S"  
    correct_answer = T(input)  # correct answer
    print("Answer is",correct_answer)
    result = grade_script(command_to_run, correct_answer)
    print(result)
