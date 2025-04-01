# I102_Homework2_Turkie

Para compilar un ejercicio, debes entrar a la carpeta del ejercicio con el comando 'cd ej1' por ejemplo, luego ejecutar el comando 'make' y se compilará y ejecutará el ejercicio.

2.c. ¿Qué tipo de relación existe entre los objetos curso y estudiante?


La relación entre los objetos Curso y Estudiante es una relación de agregación, específicamente una agregación con punteros inteligentes (std::shared_ptr).

La agregación se da cuando un objeto (en este caso, Curso) contiene referencias o punteros a otros objetos (Estudiante), pero estos objetos pueden existir independientemente del primero. Es decir, un estudiante puede existir fuera de un curso y también puede estar en varios cursos sin que su existencia dependa de ellos.
