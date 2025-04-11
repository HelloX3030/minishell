# Welcome

# Problems
- echo -nnnn
- cd -
    => new line?
    => old pwd
    => what when old_pwd and home are not set?

# Leaks Check
{
    ignore_libreadline_leaks
    Memcheck:Leak
    ...
    obj:*/libreadline.so.*
}

valgrind --leak-check=full --show-leak-kinds=all --gen-suppressions=all --suppressions=supp.supp ./minishell_debug
