#pragma once
#ifndef MEM_HPP
#define MEM_HPP

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

#include "file_loader.hpp"
#include "string_helper.hpp"

/**
 * @brief Class for storing system memory information.
 * @author Lilith Ernst
 * 
 * @version 4-30-23
 */
class mem {
    private:
    long TotalMemory;
    long FreeMemory;
    long AvailableMemory;
    long Buffers;
    long Cached;
    long SwapCached;
    long Active;
    long Inactive;
    long ActiveAnon;
    long InactiveAnon;
    long ActiveFile;
    long InactiveFile;
    long Unevictable;
    long Mlocked;
    long SwapTotal;
    long SwapFree;
    long Zswap;
    long Zswapped;
    long Dirty;
    long Writeback;
    long AnonPages;
    long Mapped;
    long Shmem;
    long Kreclaimable;
    long Slab;
    long Sreclaimable;
    long Sunreclaim;
    long KernelStack;
    long PageTables;
    long SecPageTables;
    long NFSUnstable;
    long Bounce;
    long WritebackTmp;
    long CommitLimit;
    long CommittedAs;
    long VmallocTotal;
    long VmallocUsed;
    long VmallocChunk;
    long Percpu;
    long HardwareCorrupted;
    long AnonHugePages;
    long ShmemHugePages;
    long ShmemPmdMapped;
    long FileHugePages;
    long FilePmdMapped;
    long CmaTotal;
    long CmaFree;
    long HugePagesTotal;
    long HugePagesFree;
    long HugePagesRsvd;
    long HugePagesSurp;
    long Hugepagesize;
    long Hugetlb;
    long Directmap4k;
    long Directmap2m;
    long Directmap1g;
    
    enum FIELDS {
        memory_total, memory_free, memory_available, buffers, cached, swap_cached, active, inactive, active_anon, inactive_anon, active_file,
        inactive_file, unevictable, mlocked, swap_total, swap_free, zswap, zswapped, dirty, writeback, anon_pages, mapped, shmem, kreclaimable,
        slab, sreclaimable, sunreclaim, kernel_stack, page_tables, nfs_unstable, bounce, writeback_tmp, commit_limit, committed_as,
        vmalloc_total, vmalloc_used, vmalloc_chunk, percpu, hardware_corrupted, anon_huge_pages, shmem_huge_pages, shmem_pmd_mapped,
        file_huge_pages, file_pmd_mapped, cmatotal, cmafree, huge_pages_total, huge_pages_free, huge_pages_rsvd, huge_pages_surp,
        hugepagesize, hugetlb, directmap_4k, directmap_2m, directmap_1g, sec_page_tables
    };

    std::map<std::string, FIELDS> field_map = {
        {"MemFree", mem::FIELDS::memory_free}, {"MemAvailable", mem::FIELDS::memory_available}, {"Buffers", mem::FIELDS::buffers},
        {"Cached", mem::FIELDS::cached}, {"SwapCached", mem::FIELDS::swap_cached}, {"Active", mem::FIELDS::active},
        {"Inactive", mem::FIELDS::inactive}, {"Active(anon)", mem::FIELDS::active_anon}, {"Inactive(anon)", mem::FIELDS::inactive_anon},
        {"Active(file)", mem::FIELDS::active_file}, {"Inactive(file)", mem::FIELDS::inactive_file}, {"Unevictable", mem::FIELDS::unevictable},
        {"Mlocked", mem::FIELDS::mlocked}, {"SwapTotal", mem::FIELDS::swap_total}, {"SwapFree", mem::FIELDS::swap_free},
        {"Zswap", mem::FIELDS::zswap}, {"Zswapped", mem::FIELDS::zswapped}, {"Dirty", mem::FIELDS::dirty}, {"Writeback", mem::FIELDS::writeback},
        {"AnonPages", mem::FIELDS::anon_pages}, {"Mapped", mem::FIELDS::mapped}, {"Shmem", mem::FIELDS::shmem}, {"KReclaimable", mem::FIELDS::kreclaimable},
        {"Slab", mem::FIELDS::slab}, {"SReclaimable", mem::FIELDS::sreclaimable}, {"SUnreclaim", mem::FIELDS::sunreclaim}, {"KernelStack", mem::FIELDS::kernel_stack},
        {"PageTables", mem::FIELDS::page_tables}, {"NFS_Unstable", mem::FIELDS::nfs_unstable}, {"Bounce", mem::FIELDS::bounce}, {"SecPageTables", mem::FIELDS::sec_page_tables},
        {"WritebackTmp", mem::FIELDS::writeback_tmp}, {"CommitLimit", mem::FIELDS::commit_limit}, {"Committed_AS", mem::FIELDS::committed_as},
        {"VmallocTotal", mem::FIELDS::vmalloc_total}, {"VmallocUsed", mem::FIELDS::vmalloc_used}, {"VmallocChunk", mem::FIELDS::vmalloc_chunk},
        {"Percpu", mem::FIELDS::percpu}, {"HardwareCorrupted", mem::FIELDS::hardware_corrupted}, {"AnonHugePages", mem::FIELDS::anon_huge_pages},
        {"ShmemHugePages", mem::FIELDS::shmem_huge_pages}, {"ShmemPmdMapped", mem::FIELDS::shmem_pmd_mapped}, {"FileHugePages", mem::FIELDS::file_huge_pages},
        {"FilePmdMapped", mem::FIELDS::file_pmd_mapped}, {"CmaTotal", mem::FIELDS::cmatotal}, {"CmaFree", mem::FIELDS::cmafree},
        {"HugePages_Total", mem::FIELDS::huge_pages_total}, {"HugePages_Free", mem::FIELDS::huge_pages_free}, {"HugePages_Rsvd", mem::FIELDS::huge_pages_rsvd},
        {"HugePages_Surp", mem::FIELDS::huge_pages_surp}, {"Hugepagesize", mem::FIELDS::hugepagesize}, {"Hugetlb", mem::FIELDS::hugetlb},
        {"DirectMap4k", mem::FIELDS::directmap_4k}, {"DirectMap2M", mem::FIELDS::directmap_2m}, {"DirectMap1G", mem::FIELDS::directmap_1g}, {"MemTotal", mem::FIELDS::memory_total}
    };

    public:

    /**
     * @brief Construct a new mem object
     * 
     */
    mem();


    /**
     * @brief Updates the memory information.
     * 
     */
    void updateInfo();

    /**
     * @brief Prints the memory information
     * 
     */
    void printMemoryInfo();
};

#endif
