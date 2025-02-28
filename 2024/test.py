import os
import subprocess

input_dir = '2024\\input'
output_dir = '2024\\output'
executable = '2024\\J.exe'

def test(input_path, expected_output_path):        
    with open(input_path, 'r') as file:
        input_data = file.read().strip()

    with open(expected_output_path, 'r') as file:
        expected_output_data = file.read().strip()


    result = subprocess.run([executable], input=input_data, text=True, capture_output=True)

    output_data = result.stdout
    if output_data.startswith("-1") or expected_output_data.startswith("-1"):
        return output_data.startswith("-1") and expected_output_data.startswith("-1")

    input = [line for line in input_data.split('\n') if line]
    n, m, k = map(int, input[0].split())
    edges = [-1] + [tuple(map(int, line.split())) for line in input[1:]]

    output = [line for line in output_data.split('\n') if line]
    path = list(map(int, output[1].split()))

    curr = int(output[0])
    last_c = edges[path[-1]][2]
    for e in path:
        if (
            not (1 <= e <= m)
            or curr not in edges[e][:2]
            or edges[e][2] == last_c
        ):
            return False
        
        last_c = edges[e][2]
        curr = edges[e][0] + edges[e][1] - curr
    
    return True


for input_file in os.listdir(input_dir):
    input_path = os.path.join(input_dir, input_file)
    expected_output_path = os.path.join(output_dir, input_file)

    if os.path.isfile(input_path):
        print(f'Running test with input file: {input_file}', end=' ')

        if test(input_path, expected_output_path):
            print('PASSED')
        else:
            print('FAILED')
