#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

#include "file_loader.cpp"

/**
 * @brief Class for storing system memory information.
 * @author Lilith Ernst
 * 
 * @version 4-30-23
 */
class mem {
    private:
    int memory_total;
    int memory_free;
    int memory_available;
    int buffers;
    int cached;
    int swap_cached;
    int active;
    int inactive;
    int active_anon;
    int inactive_anon;
    int active_file;
    int inactive_file;
    int unevictable;
    int mlocked;
    int swap_total;
    int swap_free;
    int zswap;
    int zswapped;
    int dirty;
    int writeback;
    int anon_pages;
    int mapped;
    int shmem;
    int slab;
    int sreclaimable;
    int sunreclaim;
    int kernel_stack;
    int page_tables;
    int nfs_unstable;
    int bounce;
    int writeback_tmp;
    int commit_limit;
    int committed_as;
    int vmalloc_total;
    int vmalloc_used;
    int vmalloc_chunk;
    int percpu;
    int hardware_corrupted;
    int anon_huge_pages;
    int shmem_huge_pages;
    int shmem_pmd_mapped;
    int file_huge_pages;
    int file_pmd_mapped;
    int cmatotal;
    int cmafree;
    int huge_pages_total;
    int huge_pages_free;
    int huge_pages_rsvd;
    int huge_pages_surp;
    int hugepagesize;
    int hugetlb;
    int directmap_4k;
    int directmap_2m;
    int directmap_1g;

    enum FIELDS {
        memory_free, memory_available, buffers, cached, swap_cached, active, inactive, active_anon, inactive_anon, active_file,
        inactive_file, unevictable, mlocked, swap_total, swap_free, zswap, zswapped, dirty, writeback, anon_pages, mapped, shmem,
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
        {"ZSwap", mem::FIELDS::zswap}, {"ZSwap(pooled)", mem::FIELDS::zswapped}, {"Dirty", mem::FIELDS::dirty}, {"Writeback", mem::FIELDS::writeback},
        {"AnonPages", mem::FIELDS::anon_pages}, {"Mapped", mem::FIELDS::mapped}, {"Shmem", mem::FIELDS::shmem}, {"Slab", mem::FIELDS::slab},
        {"SReclaimable", mem::FIELDS::sreclaimable}, {"SUnreclaim", mem::FIELDS::sunreclaim}, {"KernelStack", mem::FIELDS::kernel_stack},
        {"PageTables", mem::FIELDS::page_tables}, {"NFS_Unstable", mem::FIELDS::nfs_unstable}, {"Bounce", mem::FIELDS::bounce},
        {"WritebackTmp", mem::FIELDS::writeback_tmp}, {"CommitLimit", mem::FIELDS::commit_limit}, {"Committed_AS", mem::FIELDS::committed_as},
        {"VmallocTotal", mem::FIELDS::vmalloc_total}, {"VmallocUsed", mem::FIELDS::vmalloc_used}, {"VmallocChunk", mem::FIELDS::vmalloc_chunk},
        {"Percpu", mem::FIELDS::percpu}, {"HardwareCorrupted", mem::FIELDS::hardware_corrupted}, {"AnonHugePages", mem::FIELDS::anon_huge_pages},
        {"ShmemHugePages", mem::FIELDS::shmem_huge_pages}, {"ShmemPmdMapped", mem::FIELDS::shmem_pmd_mapped}, {"FileHugePages", mem::FIELDS::file_huge_pages},
        {"FilePmdMapped", mem::FIELDS::file_pmd_mapped}, {"CmaTotal", mem::FIELDS::cmatotal}, {"CmaFree", mem::FIELDS::cmafree},
        {"HugePages_Total", mem::FIELDS::huge_pages_total}, {"HugePages_Free", mem::FIELDS::huge_pages_free}, {"HugePages_Rsvd", mem::FIELDS::huge_pages_rsvd},
        {"HugePages_Surp", mem::FIELDS::huge_pages_surp}, {"Hugepagesize", mem::FIELDS::hugepagesize}, {"Hugetlb", mem::FIELDS::hugetlb},
        {"DirectMap4k", mem::FIELDS::directmap_4k}, {"DirectMap2M", mem::FIELDS::directmap_2m}, {"DirectMap1G", mem::FIELDS::directmap_1g}
    };

    public:


    /**
     * @brief Updates the memory information.
     * 
     */
    void updateInfo() {
        std::vector<std::string> memtext = file_loader::load_file("/proc/meminfo");
        
        for (auto line : memtext) {
            std::string field = string_helper::remove_whitespace(line.substr(0, line.find(":")));
            std::string value = line.substr(line.find(":") + 1);

            switch (field_map[field]) {
                case mem::FIELDS::memory_free:
                    memory_free = std::stoi(value);
                    break;

                case mem::FIELDS::memory_available:
                    memory_available = std::stoi(value);
                    break;

                case mem::FIELDS::buffers:
                    buffers = std::stoi(value);
                    break;

                case mem::FIELDS::cached:
                    cached = std::stoi(value);
                    break;

                case mem::FIELDS::swap_cached:
                    swap_cached = std::stoi(value);
                    break;

                case mem::FIELDS::active:
                    active = std::stoi(value);
                    break;

                case mem::FIELDS::inactive:
                    inactive = std::stoi(value);
                    break;

                case mem::FIELDS::active_anon:
                    active_anon = std::stoi(value);
                    break;

                case mem::FIELDS::inactive_anon:
                    inactive_anon = std::stoi(value);
                    break;

                case mem::FIELDS::active_file:
                    active_file = std::stoi(value);
                    break;

                case mem::FIELDS::inactive_file:
                    inactive_file = std::stoi(value);
                    break;

                case mem::FIELDS::unevictable:
                    unevictable = std::stoi(value);
                    break;

                case mem::FIELDS::mlocked:
                    mlocked = std::stoi(value);
                    break;
                
                case mem::FIELDS::swap_total:
                    swap_total = std::stoi(value);
                    break;

                case mem::FIELDS::swap_free:
                    swap_free = std::stoi(value);
                    break;

                case mem::FIELDS::zswap:
                    zswap = std::stoi(value);
                    break;

                case mem::FIELDS::zswapped:
                    zswapped = std::stoi(value);
                    break;

                case mem::FIELDS::dirty:
                    dirty = std::stoi(value);
                    break;

                case mem::FIELDS::writeback:
                    writeback = std::stoi(value);
                    break;

                case mem::FIELDS::anon_pages:
                    anon_pages = std::stoi(value);
                    break;

                case mem::FIELDS::mapped:
                    mapped = std::stoi(value);
                    break;

                case mem::FIELDS::shmem:
                    shmem = std::stoi(value);
                    break;

                case mem::FIELDS::slab:
                    slab = std::stoi(value);
                    break;

                case mem::FIELDS::sreclaimable:
                    sreclaimable = std::stoi(value);
                    break;

                case mem::FIELDS::sunreclaim:
                    sunreclaim = std::stoi(value);
                    break;

                case mem::FIELDS::kernel_stack:
                    kernel_stack = std::stoi(value);
                    break;

                case mem::FIELDS::page_tables:
                    page_tables = std::stoi(value);
                    break;

                case mem::FIELDS::nfs_unstable:
                    nfs_unstable = std::stoi(value);
                    break;

                case mem::FIELDS::bounce:
                    bounce = std::stoi(value);
                    break;

                case mem::FIELDS::writeback_tmp:
                    writeback_tmp = std::stoi(value);
                    break;

                case mem::FIELDS::commit_limit:
                    commit_limit = std::stoi(value);
                    break;

                case mem::FIELDS::committed_as:
                    committed_as = std::stoi(value);
                    break;

                case mem::FIELDS::vmalloc_total:    
                    vmalloc_total = std::stoi(value);
                    break;

                case mem::FIELDS::vmalloc_used:
                    vmalloc_used = std::stoi(value);
                    break;
                
                case mem::FIELDS::vmalloc_chunk:
                    vmalloc_chunk = std::stoi(value);
                    break;

                case mem::FIELDS::percpu:
                    percpu = std::stoi(value);
                    break;

                case mem::FIELDS::hardware_corrupted:
                    hardware_corrupted = std::stoi(value);
                    break;

                case mem::FIELDS::anon_huge_pages:
                    anon_huge_pages = std::stoi(value);
                    break;
                
                case mem::FIELDS::shmem_huge_pages:
                    shmem_huge_pages = std::stoi(value);
                    break;

                case mem::FIELDS::shmem_pmd_mapped:
                    shmem_pmd_mapped = std::stoi(value);
                    break;

                case mem::FIELDS::file_huge_pages:
                    file_huge_pages = std::stoi(value);
                    break;

                case mem::FIELDS::file_pmd_mapped:
                    file_pmd_mapped = std::stoi(value);
                    break;

                case mem::FIELDS::cmatotal:
                    cmatotal = std::stoi(value);
                    break;

                case mem::FIELDS::cmafree:
                    cmafree = std::stoi(value);
                    break;

                case mem::FIELDS::huge_pages_total:
                    huge_pages_total = std::stoi(value);
                    break;

                case mem::FIELDS::huge_pages_free:
                    huge_pages_free = std::stoi(value);
                    break;

                case mem::FIELDS::huge_pages_rsvd:
                    huge_pages_rsvd = std::stoi(value);
                    break;

                case mem::FIELDS::huge_pages_surp:
                    huge_pages_surp = std::stoi(value);
                    break;

                case mem::FIELDS::hugepagesize:
                    hugepagesize = std::stoi(value);
                    break;

                case mem::FIELDS::hugetlb:
                    hugetlb = std::stoi(value);
                    break;

                case mem::FIELDS::directmap_4k:
                    directmap_4k = std::stoi(value);
                    break;

                case mem::FIELDS::directmap_2m:
                    directmap_2m = std::stoi(value);
                    break;

                case mem::FIELDS::directmap_1g:
                    directmap_1g = std::stoi(value);
                    break;

                default:
                    break;

            }
        }

        //this->memory_total
    }

    /**
     * @brief Prints the memory information
     * 
     */
    void printMemoryInfo() {

        //std::cout << "Memory Total: " << memory_total << std::endl;
        std::cout << "Memory Free: " << memory_free << std::endl;
        std::cout << "Memory Available: " << memory_available << std::endl;
        std::cout << "Buffers: " << buffers << std::endl;
        std::cout << "Cached: " << cached << std::endl;
        std::cout << "Swap Cached: " << swap_cached << std::endl;
        std::cout << "Active: " << active << std::endl;
        std::cout << "Inactive: " << inactive << std::endl;
        std::cout << "Active Anon: " << active_anon << std::endl;
        std::cout << "Inactive Anon: " << inactive_anon << std::endl;
        std::cout << "Active File: " << active_file << std::endl;
        std::cout << "Inactive File: " << inactive_file << std::endl;
        std::cout << "Unevictable: " << unevictable << std::endl;
        std::cout << "Mlocked: " << mlocked << std::endl;
        std::cout << "Swap Total: " << swap_total << std::endl;
        std::cout << "Swap Free: " << swap_free << std::endl;
        std::cout << "Zswap: " << zswap << std::endl;
        std::cout << "Zswapped: " << zswapped << std::endl;
        std::cout << "Dirty: " << dirty << std::endl;
        std::cout << "Writeback: " << writeback << std::endl;
        std::cout << "Anon Pages: " << anon_pages << std::endl;
        std::cout << "Mapped: " << mapped << std::endl;
        std::cout << "Shmem: " << shmem << std::endl;
        std::cout << "Slab: " << slab << std::endl;
        std::cout << "Sreclaimable: " << sreclaimable << std::endl;
        std::cout << "Sunreclaim: " << sunreclaim << std::endl;
        std::cout << "Kernel Stack: " << kernel_stack << std::endl;
        std::cout << "Page Tables: " << page_tables << std::endl;
        std::cout << "NFS Unstable: " << nfs_unstable << std::endl;
        std::cout << "Bounce: " << bounce << std::endl;
        std::cout << "Writeback Tmp: " << writeback_tmp << std::endl;
        std::cout << "Commit Limit: " << commit_limit << std::endl;
        std::cout << "Committed As: " << committed_as << std::endl;
        std::cout << "Vmalloc Total: " << vmalloc_total << std::endl;
        std::cout << "Vmalloc Used: " << vmalloc_used << std::endl;
        std::cout << "Vmalloc Chunk: " << vmalloc_chunk << std::endl;
        std::cout << "Percpu: " << percpu << std::endl;
        std::cout << "Hardware Corrupted: " << hardware_corrupted << std::endl;
        std::cout << "Anon Huge Pages: " << anon_huge_pages << std::endl;
        std::cout << "Shmem Huge Pages: " << shmem_huge_pages << std::endl;
        std::cout << "Shmem Pmd Mapped: " << shmem_pmd_mapped << std::endl;
        std::cout << "File Huge Pages: " << file_huge_pages << std::endl;
        std::cout << "File Pmd Mapped: " << file_pmd_mapped << std::endl;
        std::cout << "CMA Total: " << cmatotal << std::endl;
        std::cout << "CMA Free: " << cmafree << std::endl;
        std::cout << "Huge Pages Total: " << huge_pages_total << std::endl;
        std::cout << "Huge Pages Free: " << huge_pages_free << std::endl;
        std::cout << "Huge Pages Rsrvd: " << huge_pages_rsvd << std::endl;
        std::cout << "Huge Pages Surp: " << huge_pages_surp << std::endl;
        std::cout << "Hugepagesize: " << hugepagesize << std::endl;
        std::cout << "Hugetlb: " << hugetlb << std::endl;
        std::cout << "Directmap 4k: " << directmap_4k << std::endl;
        std::cout << "Directmap 2M: " << directmap_2m << std::endl;
        std::cout << "Directmap 1G: " << directmap_1g << std::endl;
        std::cout << std::endl;
    }

};