#include "../header.h" // semplifica e sostituisce le tradizionali include guard basate su macro.

int scl_len(TipoSCL scl)
{
    if (!scl) return 0;
    return 1 + scl_len(scl->next); // Questa è ricorsiva pura, stile funzionale (non modifica nulla)
}

float scl_sum