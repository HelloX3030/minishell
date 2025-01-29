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

# Nachrichten xD
- Add Remote Repository:
	- From the Repositry with the Code
  	- git remote add intra(name) "url"
  	- git push intra
