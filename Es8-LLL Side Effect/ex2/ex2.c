float scl_sum(TipoSCL scl)
{
    if (!scl) return 0;
    return scl->info +scl_sum(scl->next);
}