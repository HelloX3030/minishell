# ToDo
- Signals handling
- expand variables $VAR_NAME (Leo)
- Handle Expressions (Lukas)
- Fix main.c (Lukas)
	- exit (Lukas)
- Wildcards
- Shell Level (Leo)

# Problems
- Refactor External Codes => Norm, Malloc Protection
- Leak in find_cmd_path: Valgrind Log:
==1129== 133 bytes in 4 blocks are definitely lost in loss record 23 of 67
==1129==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1129==    by 0x10CC8F: custom_copy (in /workspaces/minishell/minishell)
==1129==    by 0x10CDF4: ft_split (in /workspaces/minishell/minishell)
==1129==    by 0x10C270: find_cmd_path (externals.c:28)
==1129==    by 0x10C486: execute_ext (externals.c:73)
==1129==    by 0x10C1F6: execute (execute.c:20)
==1129==    by 0x10ADAF: execute_expression (execute_minishell.c:31)
==1129==    by 0x10ADE7: execute_minishell (execute_minishell.c:38)
==1129==    by 0x109845: handle_input (main.c:53)
==1129==    by 0x1098E0: main (main.c:82)
- Start Application without environment variables
	=> env -i ./minishell
	=> some environments need default values?
- echo -nnnnnnn 
	=> Still Flag, needs to work
	Example (works as no new line):
		- echo -nnnnnnnnnn -nn -n -nnnn -nnn -nnnnnnnn -n hi
	Example when flags turn to normal output
		- echo -nnnnnn -n -nnnnn -nnnnn-n -n hi => -nnnnn-n -n hi

# Ideen
- Für Readability: vlt e. g. eingegebene Prompts unterstreichen oder so?

# Notizen

# Nachrichten xD
- Add Remote Repository:
	- From the Repositry with the Code
  	- git remote add intra(name) "url"
  	- git push intra
- Check for Leaks
	- di: init docker container
	- Reopen in Container 
	- valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=supp.supp  ./minishell

# Ressources
- https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf

Here’s a structured summary of everything we’ve discussed so far:

---

## **Redirections in Bash**
Redirections control where a command gets its input from and where it sends its output.

| Symbol  | Meaning |
|---------|---------|
| `< file`  | Redirects **input** from `file`. |
| `> file`  | Redirects **output**, overwriting `file`. |
| `>> file` | Redirects **output**, appending to `file`. |
| `|` (pipe) | Sends output of **one command** as input to another. |

---

## **Behavior When Combining Redirections**
### **1️⃣ Basic Rules**
- **Order of `<` and `>` doesn’t matter**—Bash processes redirections **before running the command**.
- **Multiple output redirections** (`cmd > file1 > file2`) only keep the last one.
- **Multiple append redirections** (`cmd >> file1 >> file2`) send output to **both**.

### **2️⃣ Output Redirections**
| Command | Meaning |
|---------|---------|
| `cmd > file` | Writes output to `file`, overwriting it. |
| `cmd >> file` | Appends output to `file`. |
| `cmd > file1 > file2` | ❌ **Only writes to `file2`** (but `file1` is emptied). |
| `cmd >> file1 >> file2` | ✅ **Appends to both files.** |
| `cmd > /dev/null` | Discards output. |

### **3️⃣ Input Redirections**
| Command | Meaning |
|---------|---------|
| `cmd < file` | Reads input from `file`. |
| `cmd < /dev/null` | Runs `cmd` without input. |

### **4️⃣ Mixing Input & Output**
| Command | Meaning |
|---------|---------|
| `cmd < infile > outfile` | Reads from `infile`, writes to `outfile`. |
| `cmd > outfile < infile` | **Same as above** (order doesn’t matter). |
| `cmd < infile > infile` | ❌ **BAD:** Empties `infile` before reading! |
| `cmd < file1 < file2` | ❌ **Invalid** (commands can only read from one file). |
| `cmd file1 file2` | ✅ Works if `cmd` supports multiple files as arguments. |

### **5️⃣ Pipes vs. Redirections**
| Command | Meaning |
|---------|---------|
| `cmd1 | cmd2` | Sends output of `cmd1` as input to `cmd2`. |
| `cmd > file | cmd2` | ❌ Invalid (`>` runs first, but `|` expects output from `cmd1`). |
| `cmd | tee file` | ✅ Saves output **to both `file` and stdout**. |

---

## **Weird Cases**
| Command | What Happens? |
|---------|--------------|
| `cmd > cmd2` | `cmd2` is treated as a **file**, not a command. |
| `cmd > outfile < infile` | Reads from `infile`, writes to `outfile`. |
| `cmd > file1 >> file2` | Overwrites `file1`, appends to `file2`. |
| `cmd >> file1 > file2` | **Only `file2` is kept** (but `file1` is appended first). |
| `cmd > /dev/null < infile` | Reads from `infile`, discards output. |

---

## **Final Takeaways**
1. **Bash sets up all redirections (`<`, `>`, `>>`) before running the command.**
2. **`>` always overwrites, `>>` always appends.**
3. **Pipes (`|`) send output to another command, not a file.**
4. **Multiple `>` overwrite except the last one; multiple `>>` append to all.**
5. **Redirecting input (`<`) and output (`>`) together is fine.**
6. **Be careful with `cmd < infile > infile`—it erases `infile` before reading it!**

---

That’s the full summary! Let me know if you have any other edge cases you want to explore. 😊
