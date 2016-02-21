---
layout: page
title: Utility Cookbook
text: utility scripts for quick reference
---

# Makefile

~~~ make
BINS = $(patsubst %.cc, %.out, $(wildcard *.cc))
OBJS = $(patsubst %.cc, %.o, $(wildcard *.cc))
TARGET = $(BINS) $(OBJS)

CFLAGS = -std=c++11

.PHONY: debug all clean


all : $(TARGET)

debug: CFLAGS += -g
debug: $(TARGET)

.cc.o :
    clang++ -c $< -o $@ $(CFLAGS)

%.out : $(OBJS)
    clang++ -o $@ $^ $(CFLAGS)

clean:
    rm -rf $(TARGET)
~~~

Note the preceding spaces is not spaces but a single <kbd>tab</kbd>.

Debug build

~~~
make debug
~~~

Release build

~~~
make
~~~


#### Reference

* [debug and release build @ stackoverflow](http://stackoverflow.com/questions/1079832/how-can-i-configure-my-makefile-for-debug-and-release-builds)


# Brew

[How to remove outdated installed versions of homebrew backages](http://superuser.com/questions/975701/how-can-i-remove-outdated-installed-versions-of-homebrew-packages)

~~~
brew cleanup
~~~

## Python timeit script to compare performance of two executables

~~~ python
import timeit, subprocess, sys, random;

def call_generate_case():
    for _ in range(10):
        print(random.randint(1, 9));

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
run_shell_cmd("vimdiff LOG1 LOG2");
~~~

Equivalent to the following bash commands but with timeit report.

~~~
python -c 'import test_time; test_time.call_generate_case()'     # If the script name is test_time.py which directs its output to LOG
./solve1.out < LOG > LOG1
./solve2.out < LOG > LOG2
vimdiff LOG1 LOG2
~~~


#### Reference

* [Python run function from the command line @ stackoverflow](http://stackoverflow.com/questions/3987041/python-run-function-from-the-command-line)

* [How to use timeit module @ stackoverflow](http://stackoverflow.com/questions/8220801/how-to-use-timeit-module)

* [How to call an external command in Python @ stackoverflow](http://stackoverflow.com/questions/89228/calling-an-external-command-in-python)

* [Redirect stdout to a file in Python @ stackoverflow](http://stackoverflow.com/questions/4675728/redirect-stdout-to-a-file-in-python)
