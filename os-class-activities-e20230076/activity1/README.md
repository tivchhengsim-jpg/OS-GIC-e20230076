
# Class Activity 1 — System Calls in Practice

## Student Information

- Student Name: TIV Chhengsim
- Student ID: e20230076
- Environment: Ubuntu Linux on VMware
- Language: C
- Tools: GCC, strace, Linux Terminal

## Task 1 — File Creator and Reader

Four C programs were implemented to compare standard C library functions with Linux system calls.

| Program | Description |
|---|---|
| file_creator_lib.c | Creates and writes to a file using fopen(), fprintf(), and fclose(). |
| file_creator_sys.c | Creates and writes to a file using open(), write(), and close(). |
| file_reader_lib.c | Reads a file using fopen(), fgets(), and fclose(). |
| file_reader_sys.c | Reads a file using open(), read(), and close(). |

All four programs were compiled with GCC and executed successfully.

## Task 2 — Directory Listing

Two C programs were implemented:

- dir_list_lib.c uses opendir(), readdir(), and closedir().
- dir_list_sys.c uses open(), getdents64(), and close().

Both programs successfully listed files and directories in the current working directory.

## Task 3 — System Call Tracing

The strace utility was used to examine the Linux system calls made by the file creator programs.

The traces showed system calls including:

- openat() — Opens or creates files.
- write() — Writes data to files or standard output.
- close() — Closes file descriptors.

The library-based and system-call-based programs both ultimately relied on Linux kernel system calls to perform file operations.

Trace results were saved in:
- task3_strace/strace_lib_task1.txt
- task3_strace/strace_sys_task1.txt

## Task 4 — Operating System Exploration

The following Linux commands were executed:

| Command | Purpose |
|---|---|
| cat /proc/cpuinfo \| head -20 | Display CPU information |
| head -15 /proc/meminfo | Display memory information |
| cat /proc/version | Display Linux kernel version |
| ps -ef \| head -15 | List running processes |
| cat /proc/1/status \| head -20 | Inspect information about PID 1 |
| ls / | List root filesystem directories |
| uname -a | Display kernel and system information |

The results showed how Linux provides information about hardware, processes, memory, and the kernel through the /proc virtual filesystem and terminal commands.

## Evidence

The following screenshots were captured:

- screenshots/task1_output.jpg
- screenshots/task2_output.jpg
- screenshots/task3_strace_lib.jpg
- screenshots/task3_strace_sys.jpg

Command records are stored in their corresponding task folders.

## Conclusion

This activity demonstrated the differences between high-level C library functions and lower-level Linux system calls. It also showed how strace can reveal kernel interactions and how Linux exposes operating system information through the /proc filesystem.
