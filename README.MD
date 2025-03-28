# ToDo
- Handle Expressions (Leo)
- Wildcards (Lukas)

# Problems
- No more Mixed Exit Codes => the default Macros, not some self defined...
- Start Application without environment variables
	=> env -i ./minishell
	=> some environments need default values?
- Was passiert wenn wir failen ein infile zu öffnen => weitere commands werden dennoch ausgeführt, aber mit einer empty pipe
- double free falls zwei mal selbe Variable exportiert
	=> liegt vermutlich an set_env_val() => freed einen übergebenen ptr. das ist ein Seiteneffekt der einfach nur bugs rein bringt... außerdem gibt es noch im selben Code in der function export_without_equals() einen call mit set_env_val(env, arg, ""); => ein str literal, das nicht gemalloct wurde...

# Maybe
- Environment variables:
	- bash prevents modification: ppid, uid, euid, lineno, bashpid
	- bash resets/overrides them: shlvl, seconds, random, pwd, oldpwd
	- system may reset on login: path, term, logname

# Test Cases
- cat
^\^\^\^\^\
Quit: 3
- ">a"
- pipe ins nichts
- cat << EOF
> sdfsdf
> sdfsd
> fsd
> EOF
sdfsdf
sdfsd
fsd
=> Der Fall kann relativ einfach in der Main gehandelt werden, noch lange bevor der Tokenizer das Zeug eigentlich bekommt. Genau so auch "   unclosed bracktes ... "
- | `cmd < /dev/null` | Runs `cmd` without input. |

# Done 
- export VAR="            111         222        333         "
echo $VAR "$VAR" '$VAR'
111 222 333             111         222        333          $VAR
- Remove empty inputs => e. g. ls "$NON_EXISTING_VAR"
(- Environments nach alphabet sortieren) => kp warum es hier steht, aber bash macht es auch nicht... demnach nö

# Ideen
- Für Readability: vlt e. g. eingegebene Prompts unterstreichen oder so?
- Wenn Shell gestarted, e. g. "pls report all bugs to... githublink für das Minishell Project
- Unicode Characters falls command failed/funktioniert.
	- z. b. Failure
		❌ ✗ (Unicode: U+2717)
		⚠️ ⚠ (Unicode: U+26A0)
		💀 💀 (Unicode: U+1F480)
		🚫 🚫 (Unicode: U+1F6AB)
	- Succes
		✅ ✔ (Unicode: U+2714)
		🎉 🎉 (Unicode: U+1F389)
		👍 👍 (Unicode: U+1F44D)
		🟢 🟢 (Unicode: U+1F7E2)

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
