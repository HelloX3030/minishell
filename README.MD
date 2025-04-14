# Welcome

# Problems
- Hyperlink behind git hub stuff

# Leaks Check
{
    ignore_libreadline_leaks
    Memcheck:Leak
    ...
    obj:*/libreadline.so.*
}

valgrind --leak-check=full --show-leak-kinds=all --gen-suppressions=all --suppressions=supp.supp ./minishell_debug
