# Lab 2 — Linux Navigation and File Management

## Student Information

- Student name: TIV Chhengsim
- Student ID: e20230076
- Ubuntu username: gic-tiv-chhengsim
- File 1: sales north.txt
- File 2: vendor list.txt
- Owner department: Sales
- Reader department: HR
- Third department: Marketing
- Evidence files:
  - evidence/paths.txt
  - evidence/tree.txt
  - evidence/checkpoint.txt

## What I Did

| Step | My command | Current folder |
|---|---|---|
| Move first file (relative destination) | mv -- "$file1" ../reports/ | incoming/ |
| Move second file (absolute paths) | mv -- "$OSLAB_WORKSPACE/lab2/incoming/$file2" "$OSLAB_WORKSPACE/lab2/reports/" | lab2/ |
| Read report from reader department (relative path) | cat "../Sales/$file1" | TechCorp/HR/ |
| Intentional path error | cat "reports/$file1" | TechCorp/HR/ |
| Corrected relative path | cat "../../reports/$file1" | TechCorp/HR/ |

## Explanation

A correct filename can still give a "No such file or directory" error because a relative path is interpreted from the current working directory. For example, when I was inside TechCorp/HR, the path reports/sales north.txt did not work because there was no reports directory inside HR. I corrected the path to ../../reports/sales north.txt, which moves up two directory levels before entering reports. The mv command moves a file to another location, whereas cp creates another copy while keeping the original file. In this lab, I moved sales north.txt from incoming to reports, then copied it into TechCorp/Sales.

## What My Tests Do Not Prove

The ls command confirms that a file exists, but it does not prove that its contents match another file. The cmp command compares two files byte by byte, confirming that their contents are identical when no differences are reported.

