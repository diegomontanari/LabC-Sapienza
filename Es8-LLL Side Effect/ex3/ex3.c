float scl_media(TipoSCL scl)
{
    int count = 0;
    float sum = 0;

    for (TipoSCL temp = scl; temp != NULL; temp = temp->next) { // for (inizializzazione; condizione; aggiornamento) 
        sum += temp->info;
        count++;
    }

    return (count > 0) ? (sum / count) : 0; // Se la prima parentesi è verificata returna la seconda, sennò returna ciò che c'è dopo i 2 punti (sinstesi di un if else)
}