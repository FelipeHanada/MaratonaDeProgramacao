import os
import subprocess
import time

QUESTION = 'D'
SOLUTION = 'D-pq-grouped'
TIME_LIMIT = 1.5
question_dir = './SBC/' + QUESTION + '/'
input_dir = question_dir + 'input'
output_dir = question_dir + 'output'
executable = question_dir + SOLUTION + '.exe'

def run_test(input_path, expected_output_path):
    with open(input_path, 'r') as input_file, open(expected_output_path, 'r') as expected_file:
        try:
            # Use subprocess with input redirection to avoid loading the entire input file into memory
            result = subprocess.run(
                [executable],
                stdin=input_file,  # Pass the file object directly as stdin
                text=True,
                capture_output=True,
                timeout=TIME_LIMIT  # Apply the time limit
            )
            
            # Compare the output line by line to handle large expected output files
            for actual_line, expected_line in zip(result.stdout.splitlines(), expected_file):
                if actual_line.strip() != expected_line.strip():
                    return False
            
            # Ensure both files have the same number of lines
            expected_file.seek(0)  # Reset file pointer to the beginning
            if len(result.stdout.splitlines()) != sum(1 for _ in expected_file):
                return False
            
            return True
        except subprocess.TimeoutExpired:
            return False

def main():
    for input_file in os.listdir(input_dir):
        input_path = os.path.join(input_dir, input_file)
        expected_output_path = os.path.join(output_dir, input_file)

        if os.path.isfile(input_path) and os.path.isfile(expected_output_path):
            print(f'Running test with input file: {input_file}', end=' ')
            
            start_time = time.time()  # Inicia a contagem do tempo
            passed = run_test(input_path, expected_output_path)
            elapsed_time = time.time() - start_time  # Calcula o tempo decorrido
            
            if passed:
                print(f'PASSED (Time: {elapsed_time:.4f} seconds)')
            else:
                failed_type = 'TIME LIMIT' if elapsed_time > TIME_LIMIT else 'WRONG ANSWER'
                print(f'{failed_type} (Time: {elapsed_time:.4f} seconds)')

if __name__ == "__main__":
    main()