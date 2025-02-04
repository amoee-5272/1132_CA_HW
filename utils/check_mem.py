import re

def parse_exec_log(file_path):
    mem_data = {}
    
    pattern = re.compile(r'MemWrite\s*:\s*D=0x([0-9a-fA-F]+)\s*A=0x([0-9a-fA-F]+)')
    
    with open(file_path, 'r') as file:
        for line in file:
            match = pattern.search(line)
            if match:
                target_data = match.group(1)
                target_address = match.group(2)
                mem_data[target_address] = target_data

    return mem_data

def get_last_value_for_address(mem_data, target_address):
    return mem_data.get(target_address, '0')

file_path = './m5out/out_exec.txt' # file path to Exec output file
mem_data = parse_exec_log(file_path)

target_address = '7b00c' # target address to check
last_value = get_last_value_for_address(mem_data, target_address)

print(f"The last value written to address {target_address} is: 0x{last_value}")