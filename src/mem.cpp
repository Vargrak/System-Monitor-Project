#pragma once

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

#include "file_loader.cpp"
#include "string_helper.cpp"

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
    long Slab;
    long Sreclaimable;
    long Sunreclaim;
    long KernelStack;
    long PageTables;
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
        hugepagesize, hugetlb, directmap_4k, directmap_2m, directmap_1g
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
        {"PageTables", mem::FIELDS::page_tables}, {"NFS_Unstable", mem::FIELDS::nfs_unstable}, {"Bounce", mem::FIELDS::bounce},
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
    mem() {
        updateInfo();
    }


    /**
     * @brief Updates the memory information.
     * 
     */
    void updateInfo() {
        std::vector<std::string> memtext = file_loader::load_file("/proc/meminfo");
        
        for (auto line : memtext) {
            std::string field = string_helper::remove_whitespace(line.substr(0, line.find(":")));
            std::string value = string_helper::remove_whitespace(line.substr(line.find(":") + 1));

            switch (field_map[field]) {
                case mem::FIELDS::memory_total:
                    TotalMemory = std::stol(value);
                    break;

                case mem::FIELDS::memory_free:
                    FreeMemory = std::stol(value);
                    break;

                case mem::FIELDS::memory_available:
                    AvailableMemory = std::stol(value);
                    break;

                case mem::FIELDS::buffers:
                    Buffers = std::stol(value);
                    break;

                case mem::FIELDS::cached:
                    Cached = std::stol(value);
                    break;

                case mem::FIELDS::swap_cached:
                    SwapCached = std::stol(value);
                    break;

                case mem::FIELDS::active:
                    Active = std::stol(value);
                    break;

                case mem::FIELDS::inactive:
                    Inactive = std::stol(value);
                    break;

                case mem::FIELDS::active_anon:
                    ActiveAnon = std::stol(value);
                    break;

                case mem::FIELDS::inactive_anon:
                    InactiveAnon = std::stol(value);
                    break;

                case mem::FIELDS::active_file:
                    ActiveFile = std::stol(value);
                    break;

                case mem::FIELDS::inactive_file:
                    InactiveFile = std::stol(value);
                    break;

                case mem::FIELDS::unevictable:
                    Unevictable = std::stol(value);
                    break;

                case mem::FIELDS::mlocked:
                    Mlocked = std::stol(value);
                    break;
                
                case mem::FIELDS::swap_total:
                    SwapTotal = std::stol(value);
                    break;

                case mem::FIELDS::swap_free:
                    SwapFree = std::stol(value);
                    break;

                case mem::FIELDS::zswap:
                    Zswap = std::stol(value);
                    break;

                case mem::FIELDS::zswapped:
                    Zswapped = std::stol(value);
                    break;

                case mem::FIELDS::dirty:
                    Dirty = std::stol(value);
                    break;

                case mem::FIELDS::writeback:
                    Writeback = std::stol(value);
                    break;

                case mem::FIELDS::anon_pages:
                    AnonPages = std::stol(value);
                    break;

                case mem::FIELDS::mapped:
                    Mapped = std::stol(value);
                    break;

                case mem::FIELDS::shmem:
                    Shmem = std::stol(value);
                    break;

                case mem::FIELDS::kreclaimable:
                    Kreclaimable = std::stol(value);
                    break;

                case mem::FIELDS::slab:
                    Slab = std::stol(value);
                    break;

                case mem::FIELDS::sreclaimable:
                    Sreclaimable = std::stol(value);
                    break;

                case mem::FIELDS::sunreclaim:
                    Sunreclaim = std::stol(value);
                    break;

                case mem::FIELDS::kernel_stack:
                    KernelStack = std::stol(value);
                    break;

                case mem::FIELDS::page_tables:
                    PageTables = std::stol(value);
                    break;

                case mem::FIELDS::nfs_unstable:
                    NFSUnstable = std::stol(value);
                    break;

                case mem::FIELDS::bounce:
                    Bounce = std::stol(value);
                    break;

                case mem::FIELDS::writeback_tmp:
                    WritebackTmp = std::stol(value);
                    break;

                case mem::FIELDS::commit_limit:
                    CommitLimit = std::stol(value);
                    break;

                case mem::FIELDS::committed_as:
                    CommittedAs = std::stol(value);
                    break;

                case mem::FIELDS::vmalloc_total:    
                    VmallocTotal = std::stol(value);
                    break;

                case mem::FIELDS::vmalloc_used:
                    VmallocUsed = std::stol(value);
                    break;
                
                case mem::FIELDS::vmalloc_chunk:
                    VmallocChunk = std::stol(value);
                    break;

                case mem::FIELDS::percpu:
                    Percpu = std::stol(value);
                    break;

                case mem::FIELDS::hardware_corrupted:
                    HardwareCorrupted = std::stol(value);
                    break;

                case mem::FIELDS::anon_huge_pages:
                    AnonHugePages = std::stol(value);
                    break;
                
                case mem::FIELDS::shmem_huge_pages:
                    ShmemHugePages = std::stol(value);
                    break;

                case mem::FIELDS::shmem_pmd_mapped:
                    ShmemPmdMapped = std::stol(value);
                    break;

                case mem::FIELDS::file_huge_pages:
                    FileHugePages = std::stol(value);
                    break;

                case mem::FIELDS::file_pmd_mapped:
                    FilePmdMapped = std::stol(value);
                    break;

                case mem::FIELDS::cmatotal:
                    CmaTotal = std::stol(value);
                    break;

                case mem::FIELDS::cmafree:
                    CmaFree = std::stol(value);
                    break;

                case mem::FIELDS::huge_pages_total:
                    HugePagesTotal = std::stol(value);
                    break;

                case mem::FIELDS::huge_pages_free:
                    HugePagesFree = std::stol(value);
                    break;

                case mem::FIELDS::huge_pages_rsvd:
                    HugePagesRsvd = std::stol(value);
                    break;

                case mem::FIELDS::huge_pages_surp:
                    HugePagesSurp = std::stol(value);
                    break;

                case mem::FIELDS::hugepagesize:
                    Hugepagesize = std::stol(value);
                    break;

                case mem::FIELDS::hugetlb:
                    Hugetlb = std::stol(value);
                    break;

                case mem::FIELDS::directmap_4k:
                    Directmap4k = std::stol(value);
                    break;

                case mem::FIELDS::directmap_2m:
                    Directmap2m = std::stol(value);
                    break;

                case mem::FIELDS::directmap_1g:
                    Directmap1g = std::stol(value);
                    break;

                default:
                    break;

            }
        }
    }

    /**
     * @brief Prints the memory information
     * 
     */
    void printMemoryInfo() {

        std::cout << "SYSTEM MEMORY INFO:" << std::endl;
        std::cout << "Total Memory      : " << TotalMemory << std::endl;
        std::cout << "Available Memory  : " << AvailableMemory << std::endl;
        std::cout << "Buffers           : " << Buffers << std::endl;
        std::cout << "Cached            : " << Cached << std::endl;
        std::cout << "Swap Cached       : " << SwapCached << std::endl;
        std::cout << "Active            : " << Active << std::endl;
        std::cout << "Inactive          : " << Inactive << std::endl;
        std::cout << "Active Anon       : " << ActiveAnon << std::endl;
        std::cout << "Inactive Anon     : " << InactiveAnon << std::endl;
        std::cout << "Active File       : " << ActiveFile << std::endl;
        std::cout << "Inactive File     : " << InactiveFile << std::endl;
        std::cout << "Unevictable       : " << Unevictable << std::endl;
        std::cout << "Mlocked           : " << Mlocked << std::endl;
        std::cout << "Swap Total        : " << SwapTotal << std::endl;
        std::cout << "Swap Free         : " << SwapFree << std::endl;
        std::cout << "Zswap             : " << Zswap << std::endl;
        std::cout << "Zswapped          : " << Zswapped << std::endl;
        std::cout << "Dirty             : " << Dirty << std::endl;
        std::cout << "Writeback         : " << Writeback << std::endl;
        std::cout << "Anon Pages        : " << AnonPages << std::endl;
        std::cout << "Mapped            : " << Mapped << std::endl;
        std::cout << "Shmem             : " << Shmem << std::endl;
        std::cout << "Slab              : " << Slab << std::endl;
        std::cout << "Sreclaimable      : " << Sreclaimable << std::endl;
        std::cout << "Sunreclaim        : " << Sunreclaim << std::endl;
        std::cout << "Kernel Stack      : " << KernelStack << std::endl;
        std::cout << "Page Tables       : " << PageTables << std::endl;
        std::cout << "NFS Unstable      : " << NFSUnstable << std::endl;
        std::cout << "Bounce            : " << Bounce << std::endl;
        std::cout << "Writeback Tmp     : " << WritebackTmp << std::endl;
        std::cout << "Commit Limit      : " << CommitLimit << std::endl;
        std::cout << "Committed As      : " << CommittedAs << std::endl;
        std::cout << "Vmalloc Total     : " << VmallocTotal << std::endl;
        std::cout << "Vmalloc Used      : " << VmallocUsed << std::endl;
        std::cout << "Vmalloc Chunk     : " << VmallocChunk << std::endl;
        std::cout << "Percpu            : " << Percpu << std::endl;
        std::cout << "Hardware Corrupted: " << HardwareCorrupted << std::endl;
        std::cout << "Anon Huge Pages   : " << AnonHugePages << std::endl;
        std::cout << "Shmem Huge Pages  : " << ShmemHugePages << std::endl;
        std::cout << "Shmem Pmd Mapped  : " << ShmemPmdMapped << std::endl;
        std::cout << "File Huge Pages   : " << FileHugePages << std::endl;
        std::cout << "File Pmd Mapped   : " << FilePmdMapped << std::endl;
        std::cout << "Cma Total         : " << CmaTotal << std::endl;
        std::cout << "Cma Free          : " << CmaFree << std::endl;
        std::cout << "Huge Pages Total  : " << HugePagesTotal << std::endl;
        std::cout << "Huge Pages Free   : " << HugePagesFree << std::endl;
        std::cout << "Huge Pages Rsvd   : " << HugePagesRsvd << std::endl;
        std::cout << "Huge Pages Surp   : " << HugePagesSurp << std::endl;
        std::cout << "Huge Page Size    : " << Hugepagesize << std::endl;
        std::cout << "Huge TLB          : " << Hugetlb << std::endl;
        std::cout << "Direct Map 4K     : " << Directmap4k << std::endl;
        std::cout << "Direct Map 2M     : " << Directmap2m << std::endl;
        std::cout << "Direct Map 1G     : " << Directmap1g << std::endl;
    }   
};

