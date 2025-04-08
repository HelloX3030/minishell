# ToDo
- Handle Expressions (Leo)
	- Groups: () usw. => Diese werden als EXP_CMD enum angegeben, mit einem args[0] von ft_strcmp("(") == 0...
	- müssen einen Subprozess erstellen
- Fix bonus (Lukas)
- Signals für Unclosed ...

# Problems
- Start Application without environment variables
	=> env -i ./minishell
	=> some environments need default values?
- syntax error: echo test (ls && ls)

# Maybe
- issues with set_env_val free location ?
- No more Mixed Exit Codes => the default Macros, not some self defined...
- Environment variables:
	- bash prevents modification: ppid, uid, euid, lineno, bashpid
	- bash resets/overrides them: shlvl, seconds, random, pwd, oldpwd
	- system may reset on login: path, term, logname

# Test Cases
- cat
^\^\^\^\^\
Quit: 3
- ">a"
- cat << EOF
> sdfsdf
> sdfsd
> fsd
> EOF
sdfsdf
sdfsd
fsd

# Ideen
- Für Readability: vlt e. g. eingegebene Prompts unterstreichen oder so?
- Wenn Shell gestarted, e. g. "pls report all bugs to... githublink für das Minishell Project
- Links auf unsere githubs + ascii art start graphic? :D
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

