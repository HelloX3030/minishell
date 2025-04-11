# Welcome

# Leaks Check
{
    ignore_libreadline_leaks
    Memcheck:Leak
    ...
    obj:*/libreadline.so.*
}

Valgrind Flag: --suppressions=supp.supp
