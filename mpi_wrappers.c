int MPI_Allgather(const void *sendbuf, int  sendcount,MPI_Datatype sendtype, void *recvbuf, int recvcount,MPI_Datatype recvtype, MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Allgather(  sendbuf,   sendcount, sendtype,  recvbuf,  recvcount, recvtype,  comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Allgatherv(const void *sendbuf, int sendcount,MPI_Datatype sendtype, void *recvbuf, const int recvcounts[],const int displs[], MPI_Datatype recvtype, MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Allgatherv(  sendbuf,  sendcount, sendtype,  recvbuf,   recvcounts,  displs,  recvtype,  comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Allreduce(const void *sendbuf, void *recvbuf, int count,MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Allreduce(  sendbuf,  recvbuf,  count, datatype,  op,  comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Alltoall(const void *sendbuf, int sendcount,MPI_Datatype sendtype, void *recvbuf, int recvcount,MPI_Datatype recvtype, MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Alltoall(  sendbuf,  sendcount, sendtype,  recvbuf,  recvcount, recvtype,  comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Alltoallv(const void *sendbuf, const int sendcounts[],
                  const int sdispls[], MPI_Datatype sendtype,
                  void *recvbuf, const int recvcounts[],
                  const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Alltoallv(  sendbuf,   sendcounts,
                                          sdispls,  sendtype,
                                          recvbuf,   recvcounts,
                                          rdispls,  recvtype,  comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Alltoallw(const void *sendbuf, const int sendcounts[],
                  const int sdispls[], const MPI_Datatype sendtypes[],
                  void *recvbuf, const int recvcounts[], const int rdispls[],
                  const MPI_Datatype recvtypes[], MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Alltoallw(  sendbuf,   sendcounts,
                                          sdispls,   sendtypes,
                                          recvbuf,   recvcounts,   rdispls,
                                          recvtypes,  comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Barrier(MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Barrier( comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype,
              int root, MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Bcast( buffer,  count,  datatype,
                                     root,  comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Bsend(const void *buf, int count, MPI_Datatype datatype,
              int dest, int tag, MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Bsend(  buf,  count,  datatype,
                                      dest,  tag,  comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Buffer_detach(void *buf, int *size) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Buffer_detach( buf,  size);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Comm_join(int fd, MPI_Comm *intercomm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Comm_join( fd,  intercomm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_File_read_all(MPI_File fh, void *buf,
                      int count, MPI_Datatype datatype, MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_File_read_all( fh,  buf,
                         count,  datatype,  status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Exscan(const void *sendbuf, void *recvbuf, int count,
               MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Exscan(  sendbuf,  recvbuf,  count,
                                       datatype,  op,  comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_File_read_all_end(MPI_File fh, void *buf,
                          MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_File_read_all_end( fh,  buf,
                         status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_File_read_at(MPI_File fh, MPI_Offset offset,
                     void *buf, int count, MPI_Datatype datatype,
                     MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_File_read_at( fh,  offset,
                                            buf,  count,  datatype,
                                            status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_File_read_at_all(MPI_File fh, MPI_Offset offset,
                         void *buf, int count, MPI_Datatype datatype,
                         MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_File_read_at_all( fh,  offset,
                         buf,  count,  datatype,
                         status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_File_read_at_all_end(MPI_File fh, void *buf,
                             MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_File_read_at_all_end( fh,  buf,
                         status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_File_read_ordered(MPI_File fh, void *buf,
                          int count, MPI_Datatype datatype,
                          MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_File_read_ordered( fh,  buf,
                         count,  datatype,
                         status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_File_read_ordered_end(MPI_File fh, void *buf,
                              MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_File_read_ordered_end( fh,  buf,
                         status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_File_read_shared(MPI_File fh, void *buf, int count,
                         MPI_Datatype datatype, MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_File_read_shared( fh,  buf,  count,
                         datatype,  status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_File_read(MPI_File fh, void *buf,
                  int count, MPI_Datatype datatype, MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_File_read( fh,  buf,
                                         count,  datatype,  status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_File_seek_shared(MPI_File fh, MPI_Offset offset,
                         int whence) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_File_seek_shared( fh,  offset,
                         whence);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_File_write(MPI_File fh, const void *buf,
                   int count, MPI_Datatype datatype,
                   MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_File_write( fh,   buf,
                                          count,  datatype,
                                          status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_File_write_all(MPI_File fh, const void *buf,
                       int count, MPI_Datatype datatype, MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_File_write_all( fh,   buf,
                         count,  datatype,  status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_File_write_all_end(MPI_File fh, const void *buf, MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_File_write_all_end( fh,   buf,  status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_File_write_at(MPI_File fh, MPI_Offset offset, const void *buf,
                      int count, MPI_Datatype datatype, MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_File_write_at( fh,  offset,   buf,
                         count,  datatype,  status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_File_write_at_all(MPI_File fh, MPI_Offset offset, const void *buf,
                          int count, MPI_Datatype datatype, MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_File_write_at_all( fh,  offset,   buf,
                         count,  datatype,  status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_File_write_at_all_end(MPI_File fh, const void *buf,
                              MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_File_write_at_all_end( fh,   buf,
                         status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_File_write_ordered(MPI_File fh, const void *buf,
                           int count, MPI_Datatype datatype,
                           MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_File_write_ordered( fh,   buf,
                         count,  datatype,
                         status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_File_write_ordered_end(MPI_File fh, const void *buf,
                               MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_File_write_ordered_end( fh,   buf,
                         status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_File_write_shared(MPI_File fh, const void *buf, int count,
                          MPI_Datatype datatype, MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_File_write_shared( fh,   buf,  count,
                         datatype,  status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Gather(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
               void *recvbuf, int recvcount, MPI_Datatype recvtype, int root,
               MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Gather(  sendbuf,  sendcount,  sendtype,
                                       recvbuf,  recvcount,  recvtype,  root,
                                       comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Gatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype
                recvtype,
                int root, MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Gatherv(  sendbuf,  sendcount,  sendtype,
                                        recvbuf,   recvcounts,   displs,
                                        recvtype,
                                        root,  comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Mprobe(int source, int tag, MPI_Comm comm,
               MPI_Message *message, MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Mprobe( source,  tag,  comm,
                                      message,  status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Mrecv(void *buf, int count, MPI_Datatype type,
              MPI_Message *message, MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Mrecv( buf,  count,  type,
                                     message,  status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Neighbor_allgather(const void *sendbuf, int  sendcount,
                           MPI_Datatype sendtype, void *recvbuf, int recvcount,
                           MPI_Datatype recvtype, MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Neighbor_allgather(  sendbuf,   sendcount,
                         sendtype,  recvbuf,  recvcount,
                         recvtype,  comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Neighbor_allgatherv(const void *sendbuf, int sendcount,
                            MPI_Datatype sendtype, void *recvbuf, const int recvcounts[],
                            const int displs[], MPI_Datatype recvtype, MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Neighbor_allgatherv(  sendbuf,  sendcount,
                         sendtype,  recvbuf,   recvcounts,
                         displs,  recvtype,  comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Neighbor_alltoall(const void *sendbuf, int sendcount,
                          MPI_Datatype sendtype, void *recvbuf, int recvcount,
                          MPI_Datatype recvtype, MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Neighbor_alltoall(  sendbuf,  sendcount,
                         sendtype,  recvbuf,  recvcount,
                         recvtype,  comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Neighbor_alltoallv(const void *sendbuf, const int sendcounts[],
                           const int sdispls[], MPI_Datatype sendtype,
                           void *recvbuf, const int recvcounts[],
                           const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Neighbor_alltoallv(  sendbuf,   sendcounts,
                         sdispls,  sendtype,
                         recvbuf,   recvcounts,
                         rdispls,  recvtype,  comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Neighbor_alltoallw(const void *sendbuf, const int sendcounts[],
                           const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                           void *recvbuf, const int recvcounts[], const MPI_Aint rdispls[],
                           const MPI_Datatype recvtypes[], MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Neighbor_alltoallw(  sendbuf,   sendcounts,
                         sdispls,   sendtypes,
                         recvbuf,   recvcounts,   rdispls,
                         recvtypes,  comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Probe( source,  tag,  comm,  status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Recv(void *buf, int count, MPI_Datatype datatype,
             int source, int tag, MPI_Comm comm, MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Recv( buf,  count,  datatype,
                                    source,  tag,  comm,  status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Reduce(const void *sendbuf, void *recvbuf, int count,
               MPI_Datatype datatype, MPI_Op op, int root,
               MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Reduce(  sendbuf,  recvbuf,  count,
                                       datatype,  op,  root,
                                       comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Reduce_scatter(const void *sendbuf, void *recvbuf, const int recvcounts[],
                       MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Reduce_scatter(  sendbuf,  recvbuf,   recvcounts,
                         datatype,  op,  comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Reduce_scatter_block(const void *sendbuf, void *recvbuf, int recvcount,
                             MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Reduce_scatter_block(  sendbuf,  recvbuf,  recvcount,
                         datatype,  op,  comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Scan(const void *sendbuf, void *recvbuf, int count,
             MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Scan(  sendbuf,  recvbuf,  count,
                                     datatype,  op,  comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Scatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                void *recvbuf, int recvcount, MPI_Datatype recvtype, int root,
                MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Scatter(  sendbuf,  sendcount,  sendtype,
                                        recvbuf,  recvcount,  recvtype,  root,
                                        comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Scatterv(const void *sendbuf, const int sendcounts[], const int
                 displs[],
                 MPI_Datatype sendtype, void *recvbuf, int recvcount,
                 MPI_Datatype recvtype, int root, MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Scatterv(  sendbuf,   sendcounts,
                                         displs,
                                         sendtype,  recvbuf,  recvcount,
                                         recvtype,  root,  comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest,
             int tag, MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Send(  buf,  count,  datatype,  dest,
                                     tag,  comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Sendrecv(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                 int dest, int sendtag, void *recvbuf, int recvcount,
                 MPI_Datatype recvtype, int source, int recvtag,
                 MPI_Comm comm, MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Sendrecv(  sendbuf,  sendcount,  sendtype,
                                         dest,  sendtag,  recvbuf,  recvcount,
                                         recvtype,  source,  recvtag,
                                         comm,  status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Sendrecv_replace(void *buf, int count, MPI_Datatype datatype,
                         int dest, int sendtag, int source, int recvtag, MPI_Comm comm,
                         MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Sendrecv_replace( buf,  count,  datatype,
                         dest,  sendtag,  source,  recvtag,  comm,
                         status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Ssend(const void *buf, int count, MPI_Datatype datatype, int dest,
              int tag, MPI_Comm comm) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Ssend(  buf,  count,  datatype,  dest,
                                      tag,  comm);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Wait(MPI_Request *request, MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Wait( request,  status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Waitall(int count, MPI_Request array_of_requests[],
                MPI_Status *array_of_statuses) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Waitall( count,  array_of_requests,
                                       array_of_statuses);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Waitany(int count, MPI_Request array_of_requests[],
                int *index, MPI_Status *status) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Waitany( count,  array_of_requests,
                                       index,  status);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Waitsome(int incount, MPI_Request array_of_requests[],
                 int *outcount, int array_of_indices[],
                 MPI_Status array_of_statuses[]) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Waitsome( incount,  array_of_requests,
                                        outcount,  array_of_indices,
                                        array_of_statuses);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Win_allocate_shared (MPI_Aint size, int disp_unit, MPI_Info info,
                             MPI_Comm comm, void *baseptr, MPI_Win *win) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Win_allocate_shared ( size,  disp_unit,  info,
                         comm,  baseptr,  win);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Win_fence(int assert, MPI_Win win) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Win_fence( assert,  win);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Win_sync (MPI_Win win) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Win_sync ( win);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
int MPI_Win_wait(MPI_Win win) {
writeAndFormat(ms_now(),__func__,0);
    int wrapper_return = PMPI_Win_wait( win);
writeAndFormat(ms_now(),__func__,1);
    return wrapper_return;
}
