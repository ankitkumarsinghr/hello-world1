typedef struct _dcp_descriptor
{
u32
*next;
hw_dcp_packet1_t ctrl0;
hw_dcp_packet2_t ctrl1;
u32
*src,
*dst,
buf_size,
*payload,
stat;
} DCP_DESCRIPTOR;
DCP_DESCRIPTOR dcp1;
u32 *srcbuffer, *dstbuffer;
// set up control packet
dcp1.next = 0;
// single packet in chain
dcp1.ctrl0.U = 0;
// clear ctrl0 field
dcp1.ctrl0.B.ENABLE_MEMCOPY = 1; // enable memcopy
dcp1.ctrl0.B.DECR_SEMAPHORE = 1; // decrement semaphore
dcp1.ctrl0.B.INTERRUPT = 1;
// interrupt
dcp1.ctrl1.U = 0;
// clear ctrl1
dcp1.src = srcbuffer;
// source buffer
dcp1.dst = dstbuffer;
// destination buffer
dcp1.buf_size = 512;
// 512 bytes
dcp1.payload = NULL;
// not required
dcp1.status = 0;
// clear status
// Enable channel 0
HW_DCP_CHnCMDPTR_WR(0, dcp1);
HW_DCP_CHnSEMA_WR(0, 1);
// write packet address to pointer register
// increment semaphore by 1
// now wait for interrupt or poll
// polling code
while ( (HW_DCP_STAT_RD() & 0x01) == 0x00 );
// now check/clear channel status
if ( (HW_DCP_CHnSTAT_RD(0) & 0xFF) != 0 ) {
// an error occurred
HW_DCP_CHnSTAT_CLR(0, 0xff);
}
// clear interrupt register
HW_DCP_STA
