#ifndef VM_PAGE_H
#define VM_PAGE_H
#include <hash.h>
#include "filesys/file.h"
enum read_from 
{
    CODE_P, MMAP_P, DATA_P, DATA_MOD_P, STACK_P
};

struct spage
{
    enum read_from read_from;
    int32_t where_to_read;        // If READ_FROM == SWAP, then it indicates slot #.
    struct file *read_file;
    uint32_t read_size;
    void *upage;
    struct hash_elem hash_elem;
};

void supplemental_page_table_init (struct hash* sp_table);
struct hash_elem *supplemental_page_table_lookup (struct hash* sp_table, void *upage);
void insert_to_supplemental_page_table (struct hash* sp_table, struct spage* spage);
void delete_from_supplemental_page_table (struct hash* sp_table, void *upage);
void clear_supplemental_page_table (struct hash* sp_table);
//void clear_supplemental_page_table_mmap (struct hash *sp_table, uint8_t *from, uint8_t *to);

#endif
