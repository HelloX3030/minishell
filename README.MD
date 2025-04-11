# Welcome

# Leaks Check
{
    ignore_libreadline_leaks
    Memcheck:Leak
    ...
    obj:*/libreadline.so.*
}

Valgrind Flag: --suppressions=supp.supp

valgrind --leak-check=full --show-leak-kinds=all --gen-suppressions=all --suppressions=supp.supp ./minishell