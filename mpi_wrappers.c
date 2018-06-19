int MPI_Allgather(const void *sendbuf, int  sendcount,MPI_Datatype sendtype, void *recvbuf, int recvcount,MPI_Datatype recvtype, MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Allgather start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Allgather(  sendbuf,   sendcount, sendtype,  recvbuf,  recvcount, recvtype,  comm);      fprintf(logfile,"FUNCTION, MPI_Allgather end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Allgatherv(const void *sendbuf, int sendcount,MPI_Datatype sendtype, void *recvbuf, const int recvcounts[],const int displs[], MPI_Datatype recvtype, MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Allgatherv start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Allgatherv(  sendbuf,  sendcount, sendtype,  recvbuf,   recvcounts,  displs,  recvtype,  comm);      fprintf(logfile,"FUNCTION, MPI_Allgatherv end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Allreduce(const void *sendbuf, void *recvbuf, int count,MPI_Datatype datatype, MPI_Op op, MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Allreduce start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Allreduce(  sendbuf,  recvbuf,  count, datatype,  op,  comm);      fprintf(logfile,"FUNCTION, MPI_Allreduce end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Alltoall(const void *sendbuf, int sendcount,MPI_Datatype sendtype, void *recvbuf, int recvcount,MPI_Datatype recvtype, MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Alltoall start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Alltoall(  sendbuf,  sendcount, sendtype,  recvbuf,  recvcount, recvtype,  comm);      fprintf(logfile,"FUNCTION, MPI_Alltoall end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Alltoallv(const void *sendbuf, const int sendcounts[],
    const int sdispls[], MPI_Datatype sendtype,
    void *recvbuf, const int recvcounts[],
    const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Alltoallv start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Alltoallv(  sendbuf,   sendcounts,
      sdispls,  sendtype,
     recvbuf,   recvcounts,
      rdispls,  recvtype,  comm);      fprintf(logfile,"FUNCTION, MPI_Alltoallv end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Alltoallw(const void *sendbuf, const int sendcounts[],
    const int sdispls[], const MPI_Datatype sendtypes[],
    void *recvbuf, const int recvcounts[], const int rdispls[],
    const MPI_Datatype recvtypes[], MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Alltoallw start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Alltoallw(  sendbuf,   sendcounts,
      sdispls,   sendtypes,
     recvbuf,   recvcounts,   rdispls,
      recvtypes,  comm);      fprintf(logfile,"FUNCTION, MPI_Alltoallw end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Barrier(MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Barrier start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Barrier( comm);      fprintf(logfile,"FUNCTION, MPI_Barrier end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype,
    int root, MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Bcast start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Bcast( buffer,  count,  datatype,
     root,  comm);      fprintf(logfile,"FUNCTION, MPI_Bcast end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Bsend(const void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Bsend start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Bsend(  buf,  count,  datatype,
     dest,  tag,  comm);      fprintf(logfile,"FUNCTION, MPI_Bsend end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Buffer_detach(void *buf, int *size){      fprintf(logfile,"FUNCTION, MPI_Buffer_detach start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Buffer_detach( buf,  size);      fprintf(logfile,"FUNCTION, MPI_Buffer_detach end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Comm_join(int fd, MPI_Comm *intercomm){      fprintf(logfile,"FUNCTION, MPI_Comm_join start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Comm_join( fd,  intercomm);      fprintf(logfile,"FUNCTION, MPI_Comm_join end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_File_read_all(MPI_File fh, void *buf,
    int count, MPI_Datatype datatype, MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_File_read_all start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_File_read_all( fh,  buf,
     count,  datatype,  status);      fprintf(logfile,"FUNCTION, MPI_File_read_all end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Exscan(const void *sendbuf, void *recvbuf, int count,
    MPI_Datatype datatype, MPI_Op op, MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Exscan start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Exscan(  sendbuf,  recvbuf,  count,
     datatype,  op,  comm);      fprintf(logfile,"FUNCTION, MPI_Exscan end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_File_read_all_end(MPI_File fh, void *buf,
        MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_File_read_all_end start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_File_read_all_end( fh,  buf,
         status);      fprintf(logfile,"FUNCTION, MPI_File_read_all_end end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_File_read_at(MPI_File fh, MPI_Offset offset,
    void *buf, int count, MPI_Datatype datatype,
    MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_File_read_at start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_File_read_at( fh,  offset,
     buf,  count,  datatype,
     status);      fprintf(logfile,"FUNCTION, MPI_File_read_at end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_File_read_at_all(MPI_File fh, MPI_Offset offset,
    void *buf, int count, MPI_Datatype datatype,
    MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_File_read_at_all start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_File_read_at_all( fh,  offset,
     buf,  count,  datatype,
     status);      fprintf(logfile,"FUNCTION, MPI_File_read_at_all end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_File_read_at_all_end(MPI_File fh, void *buf,
    MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_File_read_at_all_end start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_File_read_at_all_end( fh,  buf,
     status);      fprintf(logfile,"FUNCTION, MPI_File_read_at_all_end end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_File_read_ordered(MPI_File fh, void *buf,
    int count, MPI_Datatype datatype,
    MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_File_read_ordered start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_File_read_ordered( fh,  buf,
     count,  datatype,
     status);      fprintf(logfile,"FUNCTION, MPI_File_read_ordered end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_File_read_ordered_end(MPI_File fh, void *buf,
    MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_File_read_ordered_end start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_File_read_ordered_end( fh,  buf,
     status);      fprintf(logfile,"FUNCTION, MPI_File_read_ordered_end end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_File_read_shared(MPI_File fh, void *buf, int count,
    MPI_Datatype datatype, MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_File_read_shared start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_File_read_shared( fh,  buf,  count,
     datatype,  status);      fprintf(logfile,"FUNCTION, MPI_File_read_shared end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_File_read(MPI_File fh, void *buf,
    int count, MPI_Datatype datatype, MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_File_read start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_File_read( fh,  buf,
     count,  datatype,  status);      fprintf(logfile,"FUNCTION, MPI_File_read end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_File_seek_shared(MPI_File fh, MPI_Offset offset,
    int whence){      fprintf(logfile,"FUNCTION, MPI_File_seek_shared start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_File_seek_shared( fh,  offset,
     whence);      fprintf(logfile,"FUNCTION, MPI_File_seek_shared end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_File_write(MPI_File fh, const void *buf,
    int count, MPI_Datatype datatype,
    MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_File_write start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_File_write( fh,   buf,
     count,  datatype,
     status);      fprintf(logfile,"FUNCTION, MPI_File_write end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_File_write_all(MPI_File fh, const void *buf,
    int count, MPI_Datatype datatype, MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_File_write_all start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_File_write_all( fh,   buf,
     count,  datatype,  status);      fprintf(logfile,"FUNCTION, MPI_File_write_all end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_File_write_all_end(MPI_File fh, const void *buf, MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_File_write_all_end start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_File_write_all_end( fh,   buf,  status);      fprintf(logfile,"FUNCTION, MPI_File_write_all_end end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_File_write_at(MPI_File fh, MPI_Offset offset, const void *buf,
    int count, MPI_Datatype datatype, MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_File_write_at start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_File_write_at( fh,  offset,   buf,
     count,  datatype,  status);      fprintf(logfile,"FUNCTION, MPI_File_write_at end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_File_write_at_all(MPI_File fh, MPI_Offset offset, const void *buf,
    int count, MPI_Datatype datatype, MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_File_write_at_all start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_File_write_at_all( fh,  offset,   buf,
     count,  datatype,  status);      fprintf(logfile,"FUNCTION, MPI_File_write_at_all end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_File_write_at_all_end(MPI_File fh, const void *buf,
    MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_File_write_at_all_end start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_File_write_at_all_end( fh,   buf,
     status);      fprintf(logfile,"FUNCTION, MPI_File_write_at_all_end end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_File_write_ordered(MPI_File fh, const void *buf,
    int count, MPI_Datatype datatype,
    MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_File_write_ordered start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_File_write_ordered( fh,   buf,
     count,  datatype,
     status);      fprintf(logfile,"FUNCTION, MPI_File_write_ordered end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_File_write_ordered_end(MPI_File fh, const void *buf,
    MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_File_write_ordered_end start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_File_write_ordered_end( fh,   buf,
     status);      fprintf(logfile,"FUNCTION, MPI_File_write_ordered_end end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_File_write_shared(MPI_File fh, const void *buf, int count,
    MPI_Datatype datatype, MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_File_write_shared start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_File_write_shared( fh,   buf,  count,
     datatype,  status);      fprintf(logfile,"FUNCTION, MPI_File_write_shared end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Gather(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
    void *recvbuf, int recvcount, MPI_Datatype recvtype, int root,
    MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Gather start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Gather(  sendbuf,  sendcount,  sendtype,
     recvbuf,  recvcount,  recvtype,  root,
     comm);      fprintf(logfile,"FUNCTION, MPI_Gather end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Gatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
    void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype
recvtype,
    int root, MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Gatherv start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Gatherv(  sendbuf,  sendcount,  sendtype,
     recvbuf,   recvcounts,   displs, 
recvtype,
     root,  comm);      fprintf(logfile,"FUNCTION, MPI_Gatherv end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Mprobe(int source, int tag, MPI_Comm comm,
    MPI_Message *message, MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_Mprobe start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Mprobe( source,  tag,  comm,
     message,  status);      fprintf(logfile,"FUNCTION, MPI_Mprobe end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Mrecv(void *buf, int count, MPI_Datatype type,
    MPI_Message *message, MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_Mrecv start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Mrecv( buf,  count,  type,
     message,  status);      fprintf(logfile,"FUNCTION, MPI_Mrecv end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Neighbor_allgather(const void *sendbuf, int  sendcount,
    MPI_Datatype sendtype, void *recvbuf, int recvcount,
     MPI_Datatype recvtype, MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Neighbor_allgather start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Neighbor_allgather(  sendbuf,   sendcount,
     sendtype,  recvbuf,  recvcount,
      recvtype,  comm);      fprintf(logfile,"FUNCTION, MPI_Neighbor_allgather end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Neighbor_allgatherv(const void *sendbuf, int sendcount,
    MPI_Datatype sendtype, void *recvbuf, const int recvcounts[],
    const int displs[], MPI_Datatype recvtype, MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Neighbor_allgatherv start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Neighbor_allgatherv(  sendbuf,  sendcount,
     sendtype,  recvbuf,   recvcounts,
      displs,  recvtype,  comm);      fprintf(logfile,"FUNCTION, MPI_Neighbor_allgatherv end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Neighbor_alltoall(const void *sendbuf, int sendcount,
    MPI_Datatype sendtype, void *recvbuf, int recvcount,
    MPI_Datatype recvtype, MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Neighbor_alltoall start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Neighbor_alltoall(  sendbuf,  sendcount,
     sendtype,  recvbuf,  recvcount,
     recvtype,  comm);      fprintf(logfile,"FUNCTION, MPI_Neighbor_alltoall end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Neighbor_alltoallv(const void *sendbuf, const int sendcounts[],
    const int sdispls[], MPI_Datatype sendtype,
    void *recvbuf, const int recvcounts[],
    const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Neighbor_alltoallv start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Neighbor_alltoallv(  sendbuf,   sendcounts,
      sdispls,  sendtype,
     recvbuf,   recvcounts,
      rdispls,  recvtype,  comm);      fprintf(logfile,"FUNCTION, MPI_Neighbor_alltoallv end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Neighbor_alltoallw(const void *sendbuf, const int sendcounts[],
    const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
    void *recvbuf, const int recvcounts[], const MPI_Aint rdispls[],
    const MPI_Datatype recvtypes[], MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Neighbor_alltoallw start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Neighbor_alltoallw(  sendbuf,   sendcounts,
      sdispls,   sendtypes,
     recvbuf,   recvcounts,   rdispls,
      recvtypes,  comm);      fprintf(logfile,"FUNCTION, MPI_Neighbor_alltoallw end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_Probe start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Probe( source,  tag,  comm,  status);      fprintf(logfile,"FUNCTION, MPI_Probe end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Recv(void *buf, int count, MPI_Datatype datatype,
    int source, int tag, MPI_Comm comm, MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_Recv start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Recv( buf,  count,  datatype,
     source,  tag,  comm,  status);      fprintf(logfile,"FUNCTION, MPI_Recv end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Reduce(const void *sendbuf, void *recvbuf, int count,
               MPI_Datatype datatype, MPI_Op op, int root,
               MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Reduce start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Reduce(  sendbuf,  recvbuf,  count,
                datatype,  op,  root,
                comm);      fprintf(logfile,"FUNCTION, MPI_Reduce end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Reduce_scatter(const void *sendbuf, void *recvbuf, const int recvcounts[],
    MPI_Datatype datatype, MPI_Op op, MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Reduce_scatter start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Reduce_scatter(  sendbuf,  recvbuf,   recvcounts,
     datatype,  op,  comm);      fprintf(logfile,"FUNCTION, MPI_Reduce_scatter end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Reduce_scatter_block(const void *sendbuf, void *recvbuf, int recvcount,
    MPI_Datatype datatype, MPI_Op op, MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Reduce_scatter_block start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Reduce_scatter_block(  sendbuf,  recvbuf,  recvcount,
     datatype,  op,  comm);      fprintf(logfile,"FUNCTION, MPI_Reduce_scatter_block end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Scan(const void *sendbuf, void *recvbuf, int count,
             MPI_Datatype datatype, MPI_Op op, MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Scan start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Scan(  sendbuf,  recvbuf,  count,
              datatype,  op,  comm);      fprintf(logfile,"FUNCTION, MPI_Scan end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Scatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
    void *recvbuf, int recvcount, MPI_Datatype recvtype, int root,
    MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Scatter start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Scatter(  sendbuf,  sendcount,  sendtype,
     recvbuf,  recvcount,  recvtype,  root,
     comm);      fprintf(logfile,"FUNCTION, MPI_Scatter end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Scatterv(const void *sendbuf, const int sendcounts[], const int
displs[],
    MPI_Datatype sendtype, void *recvbuf, int recvcount,
    MPI_Datatype recvtype, int root, MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Scatterv start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Scatterv(  sendbuf,   sendcounts,  
displs,
     sendtype,  recvbuf,  recvcount,
     recvtype,  root,  comm);      fprintf(logfile,"FUNCTION, MPI_Scatterv end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest,
    int tag, MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Send start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Send(  buf,  count,  datatype,  dest,
     tag,  comm);      fprintf(logfile,"FUNCTION, MPI_Send end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Sendrecv(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
    int dest, int sendtag, void *recvbuf, int recvcount,
    MPI_Datatype recvtype, int source, int recvtag,
    MPI_Comm comm, MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_Sendrecv start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Sendrecv(  sendbuf,  sendcount,  sendtype,
     dest,  sendtag,  recvbuf,  recvcount,
     recvtype,  source,  recvtag,
     comm,  status);      fprintf(logfile,"FUNCTION, MPI_Sendrecv end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Sendrecv_replace(void *buf, int count, MPI_Datatype datatype,
    int dest, int sendtag, int source, int recvtag, MPI_Comm comm,
    MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_Sendrecv_replace start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Sendrecv_replace( buf,  count,  datatype,
     dest,  sendtag,  source,  recvtag,  comm,
     status);      fprintf(logfile,"FUNCTION, MPI_Sendrecv_replace end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Ssend(const void *buf, int count, MPI_Datatype datatype, int dest,
    int tag, MPI_Comm comm){      fprintf(logfile,"FUNCTION, MPI_Ssend start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Ssend(  buf,  count,  datatype,  dest,
     tag,  comm);      fprintf(logfile,"FUNCTION, MPI_Ssend end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Wait(MPI_Request *request, MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_Wait start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Wait( request,  status);      fprintf(logfile,"FUNCTION, MPI_Wait end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Waitall(int count, MPI_Request array_of_requests[],
    MPI_Status *array_of_statuses){      fprintf(logfile,"FUNCTION, MPI_Waitall start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Waitall( count,  array_of_requests,
     array_of_statuses);      fprintf(logfile,"FUNCTION, MPI_Waitall end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Waitany(int count, MPI_Request array_of_requests[],
    int *index, MPI_Status *status){      fprintf(logfile,"FUNCTION, MPI_Waitany start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Waitany( count,  array_of_requests,
     index,  status);      fprintf(logfile,"FUNCTION, MPI_Waitany end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Waitsome(int incount, MPI_Request array_of_requests[],
    int *outcount, int array_of_indices[],
    MPI_Status array_of_statuses[]){      fprintf(logfile,"FUNCTION, MPI_Waitsome start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Waitsome( incount,  array_of_requests,
     outcount,  array_of_indices,
     array_of_statuses);      fprintf(logfile,"FUNCTION, MPI_Waitsome end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Win_allocate_shared (MPI_Aint size, int disp_unit, MPI_Info info,
                             MPI_Comm comm, void *baseptr, MPI_Win *win){      fprintf(logfile,"FUNCTION, MPI_Win_allocate_shared  start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Win_allocate_shared ( size,  disp_unit,  info,
                              comm,  baseptr,  win);      fprintf(logfile,"FUNCTION, MPI_Win_allocate_shared  end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Win_fence(int assert, MPI_Win win){      fprintf(logfile,"FUNCTION, MPI_Win_fence start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Win_fence( assert,  win);      fprintf(logfile,"FUNCTION, MPI_Win_fence end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Win_sync (MPI_Win win){      fprintf(logfile,"FUNCTION, MPI_Win_sync  start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Win_sync ( win);      fprintf(logfile,"FUNCTION, MPI_Win_sync  end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
int MPI_Win_wait(MPI_Win win){      fprintf(logfile,"FUNCTION, MPI_Win_wait start, %lu ms, %lu\n",ms_now(),gethostid());      int wrapper_return = PMPI_Win_wait( win);      fprintf(logfile,"FUNCTION, MPI_Win_wait end, %lu ms, %lu\n",ms_now(),gethostid());      return wrapper_return;    }
