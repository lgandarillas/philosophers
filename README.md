# philosophers
[Philosophers | 42 School - Rank 03]

En sistemas Ubuntu, para usar ThreadSanitizer correctamente, es necesario ejecutar ```sudo sysctl vm.mmap_rnd_bits=28```, ya que la aleatorización de memoria predeterminada (32 bits) puede causar errores en la herramienta. Reducir este valor a 28 bits asegura que ThreadSanitizer funcione sin problemas.