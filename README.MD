# ToDo
- Prototype
	- Readline simpler Prototyp der schlicht auf Input lauscht
	- Erstes Feature Umsetzten: executables starten. 
	- Erstes Parsing... 
		- Recursive/Teilbereiche welche wiederum interpretiert werden müssen

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
