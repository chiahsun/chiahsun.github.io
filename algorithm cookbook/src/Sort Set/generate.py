import random, timeit, subprocess, sys;
# random.seed(0);

def generate_command():
    if (random.randint(0, 1) == 0):
        print("QUERY", end=' ');
    else:
        print("ADD", end=' ');
    print(random.randint(0, 100));


def call_generate_case():
    for _ in range(500000):
        generate_command();

def run_shell_cmd(cmd):
    subprocess.call(cmd.split());

sys.stdout = open('LOG', 'w');
call_generate_case();
sys.stdout = sys.__stdout__;

def run_executable(exe_name, infile_name, outfile_name):
    with open(infile_name, 'r') as infile:
        with open(outfile_name, 'w') as outfile:
            subprocess.call(exe_name, stdin=infile, stdout=outfile);

print("[Run 1]: ", timeit.timeit('run_executable("./solve1.out", "LOG", "LOG1")', number=1, setup="from __main__ import run_executable"));
print("[Run 2]: ", timeit.timeit('run_executable("./solve2.out", "LOG", "LOG2")', number=1, setup="from __main__ import run_executable"));
# run_shell_cmd("vimdiff LOG1 LOG2");
