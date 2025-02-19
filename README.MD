# ToDo
- Finish Parsing
	- All Values need to be inside of t_expression
	- Remove t_command
- Add Readline things
- Put it all together: 
	- Parser => exectutioner
- Giant Merge on master 
	- Create new subbranches 
- => Testing

# Problems
- Memory Managment:
	- Keine Globalen Variablen (welche man bei SIGINT cleanen könnte), dennoch aber muss man den derzeitigen Prozess beenden, und darf nicht nur auf das Flag Pollen...
		=> Einzige Option wirkt eine function wie void get_mem(){static char *x = malloc..., return x}, und dann cleaned man einfach das x, bzw. ein entsprechendes struct oder so, aber das ist verdammt dreist... andererseits, mit den Limitierungen fühlt es sich so an als wollten sie das man cheated... 
		=> Lösung nachdem ich ein paar Lösungen online angeschaut habe: Das Szenario einfach gar nicht handlen. Wenn Command + C man ein Sigint erhählt leaked man halt. Ist zwar dumm, aber nicht anders möglich mit den Limitierungen des Subjects... 

# Ideen
- Für Readability: vlt e. g. eingegebene Prompts unterstreichen oder so?

# Notizen
- How tgetstr() Works
    tgetstr("cl", NULL) → Clears the screen
    tgetstr("cm", NULL) → Moves the cursor (needs tgoto())
    tgetstr("so", NULL) → Starts standout (bold/bright) mode
    tgetstr("se", NULL) → Ends standout mode
    tgetstr("md", NULL) → Starts bold text
    tgetstr("me", NULL) → Resets text attributes
    tgetstr("us", NULL) → Starts underline
    tgetstr("ue", NULL) → Ends underline
- How to Manage Environment variables:
	- Link list structure:
```.c
typedef struct s_env
{
    char *key;
    char *value;
    struct s_env *next;
} t_env;

t_env *create_env_node(char *env_entry)
{
    t_env *node;
    char *delimiter = strchr(env_entry, '=');
    
    if (!delimiter) return NULL; // Invalid environment entry
    
    node = malloc(sizeof(t_env));
    if (!node) return NULL;

    node->key = strndup(env_entry, delimiter - env_entry); // Extract key
    node->value = strdup(delimiter + 1); // Extract value
    node->next = NULL;
    
    return node;
}

t_env *init_env(char **envp)
{
    t_env *head = NULL;
    t_env *current = NULL;
    
    for (int i = 0; envp[i]; i++)
    {
        t_env *new_node = create_env_node(envp[i]);
        if (!new_node) continue;

        if (!head)
            head = new_node;
        else
            current->next = new_node;
        
        current = new_node;
    }
    return head;
}
t_env *create_env_node(char *env_entry)
{
    t_env *node;
    char *delimiter = strchr(env_entry, '=');
    
    if (!delimiter) return NULL; // Invalid environment entry
    
    node = malloc(sizeof(t_env));
    if (!node) return NULL;

    node->key = strndup(env_entry, delimiter - env_entry); // Extract key
    node->value = strdup(delimiter + 1); // Extract value
    node->next = NULL;
    
    return node;
}

t_env *init_env(char **envp)
{
    t_env *head = NULL;
    t_env *current = NULL;
    
    for (int i = 0; envp[i]; i++)
    {
        t_env *new_node = create_env_node(envp[i]);
        if (!new_node) continue;

        if (!head)
            head = new_node;
        else
            current->next = new_node;
        
        current = new_node;
    }
    return head;
}
char *get_env_value(t_env *env, const char *key)
{
    while (env)
    {
        if (strcmp(env->key, key) == 0)
            return env->value;
        env = env->next;
    }
    return NULL;
}
void set_env_value(t_env *env, const char *key, const char *new_value)
{
    while (env)
    {
        if (strcmp(env->key, key) == 0)
        {
            free(env->value);
            env->value = strdup(new_value);
            return;
        }
        env = env->next;
    }
}
void add_env_var(t_env **env, const char *key, const char *value)
{
    t_env *new_node = malloc(sizeof(t_env));
    if (!new_node) return;
    
    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = *env;
    
    *env = new_node; // Insert at the head
}
void remove_env_var(t_env **env, const char *key)
{
    t_env *current = *env;
    t_env *prev = NULL;

    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            if (prev)
                prev->next = current->next;
            else
                *env = current->next; // Remove the head
            
            free(current->key);
            free(current->value);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}
int main(int argc, char **argv, char **envp)
{
    // Initialize environment list
    t_env *env_list = init_env(envp);

    // Print all environment variables
    print_env(env_list);

    // Get a specific variable
    printf("\nHOME = %s\n", get_env_value(env_list, "HOME"));

    // Add a new variable
    add_env_var(&env_list, "NEW_VAR", "1234");
    printf("\nAfter adding NEW_VAR:\n");
    print_env(env_list);

    // Update an existing variable
    set_env_value(env_list, "NEW_VAR", "5678");
    printf("\nAfter updating NEW_VAR:\n");
    print_env(env_list);

    // Remove a variable
    remove_env_var(&env_list, "NEW_VAR");
    printf("\nAfter removing NEW_VAR:\n");
    print_env(env_list);

    // Cleanup
    free_env(env_list);
    return 0;
}

```
- Bonus:
	- First split up into && parts
	- than split up into || 
	- => than the normal data structurs with | pipes

# Nachrichten xD
- Add Remote Repository:
	- From the Repositry with the Code
  	- git remote add intra(name) "url"
  	- git push intra

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