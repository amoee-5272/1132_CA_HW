base_path = r'C:\Users\wuyiz\Downloads\CA_HW3'

def run_test():
    answer_path = rf'{base_path}\answer.txt'
    golden_path = rf'{base_path}\golden.txt'

    with open(answer_path, 'r') as f1, open(golden_path, 'r') as f2:
        answer = f1.read()
        golden = f2.read()

    if answer == golden:
        print("Pass!")
    else:
        print("Fail!")

if __name__ == "__main__":
    run_test()
