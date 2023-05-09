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
 * @version 5-9-23
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

        //Getters for the memory information
        long getTotalMemory() { return TotalMemory; }
        long getFreeMemory() { return FreeMemory; }
        long getAvailableMemory() { return AvailableMemory; }

        long getBuffers() { return Buffers; }
        long getCached() { return Cached; }
        long getSwapCached() { return SwapCached; }

        long getActive() { return Active; }
        long getInactive() { return Inactive; }
        long getActiveAnon() { return ActiveAnon; }

        long getInactiveAnon() { return InactiveAnon; }
        long getActiveFile() { return ActiveFile; }
        long getInactiveFile() { return InactiveFile; }

        long getUnevictable() { return Unevictable; }
        long getMlocked() { return Mlocked; }
        long getSwapTotal() { return SwapTotal; }

        long getSwapFree() { return SwapFree; }
        long getZswap() { return Zswap; }
        long getZswapped() { return Zswapped; }

        long getDirty() { return Dirty; }
        long getWriteback() { return Writeback; }
        long getAnonPages() { return AnonPages; }

        long getMapped() { return Mapped; }
        long getShmem() { return Shmem; }
        long getKreclaimable() { return Kreclaimable; }

        long getSlab() { return Slab; }
        long getSreclaimable() { return Sreclaimable; }
        long getSunreclaim() { return Sunreclaim; }

        long getKernelStack() { return KernelStack; }
        long getPageTables() { return PageTables; }
        long getSecPageTables() { return SecPageTables; }

        long getNFSUnstable() { return NFSUnstable; }
        long getBounce() { return Bounce; }
        long getWritebackTmp() { return WritebackTmp; }

        long getCommitLimit() { return CommitLimit; }
        long getCommittedAs() { return CommittedAs; }
        long getVmallocTotal() { return VmallocTotal; }

        long getVmallocUsed() { return VmallocUsed; }
        long getVmallocChunk() { return VmallocChunk; }
        long getPercpu() { return Percpu; }

        long getHardwareCorrupted() { return HardwareCorrupted; }
        long getAnonHugePages() { return AnonHugePages; }
        long getShmemHugePages() { return ShmemHugePages; }

        long getShmemPmdMapped() { return ShmemPmdMapped; }
        long getFileHugePages() { return FileHugePages; }
        long getFilePmdMapped() { return FilePmdMapped; }

        long getCmaTotal() { return CmaTotal; }
        long getCmaFree() { return CmaFree; }
        long getHugePagesTotal() { return HugePagesTotal; }

        long getHugePagesFree() { return HugePagesFree; }
        long getHugePagesRsvd() { return HugePagesRsvd; }
        long getHugePagesSurp() { return HugePagesSurp; }

        long getHugepagesize() { return Hugepagesize; }
        long getHugetlb() { return Hugetlb; }
        long getDirectmap4k() { return Directmap4k; }

        long getDirectmap2m() { return Directmap2m; }
        long getDirectmap1g() { return Directmap1g; }

        //Setters for the memory information
        void setTotalMemory(long totalMemory) { this->TotalMemory = totalMemory; }
        void setFreeMemory(long freeMemory) { this->FreeMemory = freeMemory; }
        void setAvailableMemory(long availableMemory) { this->AvailableMemory = availableMemory; }

        void setBuffers(long _buffers) { this->Buffers = _buffers; }
        void setCached(long _cached) { this->Cached = _cached; }
        void setSwapCached(long _SwapCached) { this->SwapCached = _SwapCached; }

        void setActive(long _active) { this->Active = _active; }
        void setInactive(long _inactive) { this->Inactive = _inactive; }
        void setActiveAnon(long _activeAnon) { this->ActiveAnon = _activeAnon; }

        void setInactiveAnon(long _inactiveAnon) { this->InactiveAnon = _inactiveAnon; }
        void setActiveFile(long _activeFile) { this->ActiveFile = _activeFile; }
        void setInactiveFile(long _inactiveFile) { this->InactiveFile = _inactiveFile; }

        void setUnevictable(long _unevictable) { this->Unevictable = _unevictable; }
        void setMlocked(long _mlocked) { this->Mlocked = _mlocked; }
        void setSwapTotal(long _swapTotal) { this->SwapTotal = _swapTotal; }

        void setSwapFree(long _swapFree) { this->SwapFree = _swapFree; }
        void setZswap(long _zswap) { this->Zswap = _zswap; }
        void setZswapped(long _zswapped) { this->Zswapped = _zswapped; }

        void setDirty(long _dirty) { this->Dirty = _dirty; }
        void setWriteback(long _writeback) { this->Writeback = _writeback; }
        void setAnonPages(long _anonPages) { this->AnonPages = _anonPages; }

        void setMapped(long _mapped) { this->Mapped = _mapped; }
        void setShmem(long _shmem) { this->Shmem = _shmem; }
        void setKreclaimable(long _kreclaimable) { this->Kreclaimable = _kreclaimable; }

        void setSlab(long _slab) { this->Slab = _slab; }
        void setSreclaimable(long _sreclaimable) { this->Sreclaimable = _sreclaimable; }
        void setSunreclaim(long _sunreclaim) { this->Sunreclaim = _sunreclaim; }

        void setKernelStack(long kernelStack) { this->KernelStack = kernelStack; }
        void setPageTables(long pageTables) { this->PageTables = pageTables; }
        void setSecPageTables(long secPageTables) { this->SecPageTables = secPageTables; }

        void setNFSUnstable(long nfsUnstable) { this->NFSUnstable = nfsUnstable; }
        void setBounce(long _bounce) { this->Bounce = _bounce; }
        void setWritebackTmp(long writebackTmp) { this->WritebackTmp = writebackTmp; }

        void setCommitLimit(long commitLimit) { this->CommitLimit = commitLimit; }
        void setCommittedAs(long committedAs) { this->CommittedAs = committedAs; }
        void setVmallocTotal(long vmallocTotal) { this->VmallocTotal = vmallocTotal; }

        void setVmallocUsed(long vmallocUsed) { this->VmallocUsed = vmallocUsed; }
        void setVmallocChunk(long vmallocChunk) { this->VmallocChunk = vmallocChunk; }
        void setPercpu(long _percpu) { this->Percpu = _percpu; }

        void setHardwareCorrupted(long hardwareCorrupted) { this->HardwareCorrupted = hardwareCorrupted; }
        void setAnonHugePages(long anonHugePages) { this->AnonHugePages = anonHugePages; }
        void setShmemHugePages(long shmemHugePages) { this->ShmemHugePages = shmemHugePages; }

        void setShmemPmdMapped(long shmemPmdMapped) { this->ShmemPmdMapped = shmemPmdMapped; }
        void setFileHugePages(long fileHugePages) { this->FileHugePages = fileHugePages; }
        void setFilePmdMapped(long filePmdMapped) { this->FilePmdMapped = filePmdMapped; }

        void setCmaTotal(long cmaTotal) { this->CmaTotal = cmaTotal; }
        void setCmaFree(long cmaFree) { this->CmaFree = cmaFree; }
        void setHugePagesTotal(long hugePagesTotal) { this->HugePagesTotal = hugePagesTotal; }

        void setHugePagesFree(long hugePagesFree) { this->HugePagesFree = hugePagesFree; }
        void setHugePagesRsvd(long hugePagesRsvd) { this->HugePagesRsvd = hugePagesRsvd; }
        void setHugePagesSurp(long hugePagesSurp) { this->HugePagesSurp = hugePagesSurp; }

        void setHugepagesize(long _hugepagesize) { this->Hugepagesize = _hugepagesize; }
        void setHugetlb(long _hugetlb) { this->Hugetlb = _hugetlb; }
        void setDirectmap4k(long directmap4k) { this->Directmap4k = directmap4k; }

        void setDirectmap2m(long directmap2m) { this->Directmap2m = directmap2m; }
        void setDirectmap1g(long directmap1g) { this->Directmap1g = directmap1g; }

};

#endif
