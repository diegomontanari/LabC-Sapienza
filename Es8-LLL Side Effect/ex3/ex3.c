float scl_media_aux(TipoSCL scl, int *count) {
    if (!scl) { // Caso base: lista vuota
        *count = 0;
        return 0;
    }
    int cnt = 0;
    float sum = scl_media_aux(scl->next, &cnt); // Chiamata ricorsiva
    *count = cnt + 1; // Incrementa il conteggio
    return sum + scl->info; // Accumula la somma
}

float scl_media(TipoSCL scl) {
    int count;
    float sum = scl_media_aux(scl, &count); // Calcola somma e conteggio
    return (count == 0) ? 0 : sum / count; // Calcola la media
}