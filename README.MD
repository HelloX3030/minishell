# ToDo
- Handle Expressions (Lukas)
- expand variables $VAR_NAME -- ich wuerde das in den Parser machen, weil wie wir gerade "" und '' handeln passt noch nicht und wenn wir das richtig machen, kann ich im exec nicht mehr bestimmen ob etwas expanded werden muss oder nicht(Leo)
- Signals handling => leo
- Wildcards
- Hanlde $? => Exit Codes -- exit codes erledigt, mini_exit handelt das jetzt, expansion teil fehlt noch (leo: 10.03) => leo 
- Succes/Failure for execute Function => to handle the expressions

# Problems
- Refactor External Codes => Norm, Malloc Protection
- No more Mixed Exit Codes => the default Macros, not some self defined...
- Start Application without environment variables
	=> env -i ./minishell
	=> some environments need default values?
- remove free_array function and replace it with free_strs
	=> or move it to libft
- Environment variables:
	- bash prevents modification: ppid, uid, euid, lineno, bashpid
	- bash resets/overrides them: shlvl, seconds, random, pwd, oldpwd
	- system may reset on login: path, term, logname
- echo -nnnnnnn => Still Flag, needs to work Example (works as no new line): - echo -nnnnnnnnnn -nn -n -nnnn -nnn -nnnnnnnn -n hi Example when flags turn to normal output - echo -nnnnnn -n -nnnnn -nnnnn-n -n hi => -nnnnn-n -n hi
- remove mixed exit calls => exit_minishell vs real exit

# Test Cases
- export test=abc
- export test
=> test darf nicht geleert werden	- bei mir funktioniert dieser test case wie angegeben, gab es bei dir fehler? (leo: 10.03)

- pipe ins nichts

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
- how to use lldb:
1. Starting and Running a Program
Command	Description
lldb ./my_program	Start debugging my_program.
run (or r)	Start running the program.
run arg1 arg2	Run with command-line arguments.
process attach -p <pid>	Attach to a running process.
2. Breakpoints
Command	Description
b main	Set a breakpoint at main.
b my_function	Break at my_function().
b my_program.c:10	Break at line 10 in my_program.c.
br list	List all breakpoints.
br delete	Delete all breakpoints.
br delete <id>	Delete a specific breakpoint by ID.
br disable <id>	Disable a breakpoint without removing it.
3. Stepping Through Code
Command	Alias	Description
next	n	Step over (execute line, but don't enter functions).
step	s	Step into (go inside function calls).
finish		Step out (run until function returns).
continue	c	Resume execution until the next breakpoint.
4. Inspecting the Program
Command	Alias	Description
frame variable	fr v	Show local variables in the current stack frame.
print var_name	p var_name	Print a variable’s value.
memory read var_name		Read memory at var_name (useful for pointers).
bt		Show the backtrace (call stack).
thread list		List all threads.
thread backtrace		Show call stacks of all threads.
5. Modifying Variables
Command	Description
expr var_name = 42	Change the value of var_name to 42.
expr (int) var_name = 10	Explicitly cast var_name to int and set it to 10.
6. Exiting lldb
Command	Description
quit	Exit lldb.
exit	Alternative way to exit.

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
