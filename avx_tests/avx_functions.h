

void avx_F(MD5 *md5, __m128i a, __m128i b, __m128i c, __m128i d, __m128i m, unsigned int s, unsigned int t){

	//#define F(b, c, d) ((b & c) | (~b & d))

	md5 -> f1 = _mm_and_si128(b,c);
  	md5 -> f2 = _mm_andnot_si128(b,d);
  	md5 -> f3 = _mm_or_si128(md5->f1,md5->f2);

  	md5 -> f4 = _mm_add_epi32(a,md5->f3);
  	md5 -> f5 = _mm_add_epi32(m,t);
  	md5 -> f6 = _mm_add_epi32(md5->f4,md5->f5);

  	md5 -> f7 = _mm_slli_epi32(md5->f6,s);
  	md5 -> f8 = _mm_srli_epi32(md5->f6,(32-s));
  	md5 -> f9 = _mm_or_si128(md5->f7,md5->f8);

  	a = _mm_add_epi32(md5->f9,b);
}

void avx_G(MD5 *md5, __m128i a, __m128i b, __m128i c, __m128i d, __m128i m, unsigned int s, unsigned int t){

	//#define G(b, c, d) ((b & d) | (c & ~d))

	md5 -> f1 = _mm_and_si128(b,d);
  	md5 -> f2 = _mm_andnot_si128(d,c);
  	md5 -> f3 = _mm_or_si128(md5->f1,md5->f2);

  	md5 -> f4 = _mm_add_epi32(a,md5->f3);
  	md5 -> f5 = _mm_add_epi32(m,t);
  	md5 -> f6 = _mm_add_epi32(md5->f4,md5->f5);

  	md5 -> f7 = _mm_slli_epi32(md5->f6,s);
  	md5 -> f8 = _mm_srli_epi32(md5->f6,(32-s));
  	md5 -> f9 = _mm_or_si128(md5->f7,md5->f8);

  	a = _mm_add_epi32(md5->f9,b);
}

void avx_H(MD5 *md5, __m128i a, __m128i b, __m128i c, __m128i d, __m128i m, unsigned int s, unsigned int t){

	//#define H(b, c, d) ((b ^ c ^ d))

	md5 -> f1 = _mm_xor_si128(b,c);
  	md5 -> f2 = _mm_xor_si128(md5->f1,d);

  	md5 -> f3 = _mm_add_epi32(a,md5->f2);
  	md5 -> f4 = _mm_add_epi32(m,t);
  	md5 -> f5 = _mm_add_epi32(md5->f3,md5->f4);

  	md5 -> f6 = _mm_slli_epi32(md5->f5,s);
  	md5 -> f7 = _mm_srli_epi32(md5->f5,(32-s));
  	md5 -> f8 = _mm_or_si128(md5->f6,md5->f7);

  	a = _mm_add_epi32(md5->f8,b);
}

void avx_I(MD5 *md5, __m128i a, __m128i b, __m128i c, __m128i d, __m128i m, unsigned int s, unsigned int t, __m128i l){

	//#define I(b, c, d) ((c ^ (b | ~d)))

	md5 -> f1 = _mm_andnot_si128(d,l);
  	md5 -> f2 = _mm_or_si128(md5->f1,b);
  	md5 -> f3 = _mm_xor_si128(md5->f2,c);

  	md5 -> f4 = _mm_add_epi32(a,md5->f3);
  	md5 -> f5 = _mm_add_epi32(m,t);
  	md5 -> f6 = _mm_add_epi32(md5->f4,md5->f5);

  	md5 -> f7 = _mm_slli_epi32(md5->f6,s);
  	md5 -> f8 = _mm_srli_epi32(md5->f6,(32-s));
  	md5 -> f9 = _mm_or_si128(md5->f7,md5->f8);

  	a = _mm_add_epi32(md5->f9,b);
}

	
	

void avx_manipulate(MD5 *md5){

    __m128i a = _mm_setr_epi32(0x67452301,0x67452301,0x67452301,0x67452301);
    __m128i b = _mm_setr_epi32(0xefcdab89,0xefcdab89,0xefcdab89,0xefcdab89);
    __m128i c = _mm_setr_epi32(0x98badcfe,0x98badcfe,0x98badcfe,0x98badcfe);
    __m128i d = _mm_setr_epi32(0x10325476,0x10325476,0x10325476,0x10325476);
    __m128i l = _mm_setr_epi32(0x11111111,0x11111111,0x11111111,0x11111111);

    avx_F(md5, a, b, c, d, md5 -> avx0, S[0], T[0]);


    avx_F(md5, a, b, c, d, md5->avx0,  S[0],  T[0]);
    avx_F(md5, d, a, b, c, md5->avx1,  S[1],  T[1]);
    avx_F(md5, c, d, a, b, md5->avx2,  S[2],  T[2]);
    avx_F(md5, b, c, d, a, md5->avx3,  S[3],  T[3]);
    avx_F(md5, a, b, c, d, md5->avx4,  S[4],  T[4]);
    avx_F(md5, d, a, b, c, md5->avx5,  S[5],  T[5]);
    avx_F(md5, c, d, a, b, md5->avx6,  S[6],  T[6]);
    avx_F(md5, b, c, d, a, md5->avx7,  S[7],  T[7]);
    avx_F(md5, a, b, c, d, md5->avx8,  S[8],  T[8]);
    avx_F(md5, d, a, b, c, md5->avx9,  S[9],  T[9]);
    avx_F(md5, c, d, a, b, md5->avx10, S[10], T[10]);
    avx_F(md5, b, c, d, a, md5->avx11, S[11], T[11]);
    avx_F(md5, a, b, c, d, md5->avx12, S[12], T[12]);
    avx_F(md5, d, a, b, c, md5->avx13, S[13], T[13]);
    avx_F(md5, c, d, a, b, md5->avx14, S[14], T[14]);
    avx_F(md5, b, c, d, a, md5->avx15, S[15], T[15]);

    avx_G(md5, a, b, c, d, md5->avx1,  S[16], T[16]);
    avx_G(md5, d, a, b, c, md5->avx6,  S[17], T[17]);
    avx_G(md5, c, d, a, b, md5->avx11, S[18], T[18]);
    avx_G(md5, b, c, d, a, md5->avx0,  S[19], T[19]);
    avx_G(md5, a, b, c, d, md5->avx5,  S[20], T[20]);
    avx_G(md5, d, a, b, c, md5->avx10, S[21], T[21]);
    avx_G(md5, c, d, a, b, md5->avx15, S[22], T[22]);
    avx_G(md5, b, c, d, a, md5->avx4,  S[23], T[23]);
    avx_G(md5, a, b, c, d, md5->avx9,  S[24], T[24]);
    avx_G(md5, d, a, b, c, md5->avx14, S[25], T[25]);
    avx_G(md5, c, d, a, b, md5->avx3,  S[26], T[26]);
    avx_G(md5, b, c, d, a, md5->avx8,  S[27], T[27]);
    avx_G(md5, a, b, c, d, md5->avx13, S[28], T[28]);
    avx_G(md5, d, a, b, c, md5->avx2,  S[29], T[29]);
    avx_G(md5, c, d, a, b, md5->avx7,  S[30], T[30]);
    avx_G(md5, b, c, d, a, md5->avx12, S[31], T[31]);

    avx_H(md5, a, b, c, d, md5->avx5,  S[32], T[32]);
    avx_H(md5, d, a, b, c, md5->avx8,  S[33], T[33]);
    avx_H(md5, c, d, a, b, md5->avx11, S[34], T[34]);
    avx_H(md5, b, c, d, a, md5->avx14, S[35], T[35]);
    avx_H(md5, a, b, c, d, md5->avx1,  S[36], T[36]);
    avx_H(md5, d, a, b, c, md5->avx4,  S[37], T[37]);
    avx_H(md5, c, d, a, b, md5->avx7,  S[38], T[38]);
    avx_H(md5, b, c, d, a, md5->avx10, S[39], T[39]);
    avx_H(md5, a, b, c, d, md5->avx13, S[40], T[40]);
    avx_H(md5, d, a, b, c, md5->avx0,  S[41], T[41]);
    avx_H(md5, c, d, a, b, md5->avx3,  S[42], T[42]);
    avx_H(md5, b, c, d, a, md5->avx6,  S[43], T[43]);
    avx_H(md5, a, b, c, d, md5->avx9,  S[44], T[44]);
    avx_H(md5, d, a, b, c, md5->avx12, S[45], T[45]);
    avx_H(md5, c, d, a, b, md5->avx15, S[46], T[46]);
    avx_H(md5, b, c, d, a, md5->avx2,  S[47], T[47]);

    avx_I(md5, a, b, c, d, md5->avx0,  S[48], T[48], l);
    avx_I(md5, d, a, b, c, md5->avx7,  S[49], T[49], l);
    avx_I(md5, c, d, a, b, md5->avx14, S[50], T[50], l);
    avx_I(md5, b, c, d, a, md5->avx5,  S[51], T[51], l);
    avx_I(md5, a, b, c, d, md5->avx12, S[52], T[52], l);
    avx_I(md5, d, a, b, c, md5->avx3,  S[53], T[53], l);
    avx_I(md5, c, d, a, b, md5->avx10, S[54], T[54], l);
    avx_I(md5, b, c, d, a, md5->avx1,  S[55], T[55], l);
    avx_I(md5, a, b, c, d, md5->avx8,  S[56], T[56], l);
    avx_I(md5, d, a, b, c, md5->avx15, S[57], T[57], l);
    avx_I(md5, c, d, a, b, md5->avx6,  S[58], T[58], l);
    avx_I(md5, b, c, d, a, md5->avx13, S[59], T[59], l);
    avx_I(md5, a, b, c, d, md5->avx4,  S[60], T[60], l);
    avx_I(md5, d, a, b, c, md5->avx11, S[61], T[61], l);
    avx_I(md5, c, d, a, b, md5->avx2,  S[62], T[62], l);
    avx_I(md5, b, c, d, a, md5->avx9,  S[63], T[63], l);

    md5->avx_hash0 = md5->avxa + a;
    md5->avx_hash1 = md5->avxb + b;
    md5->avx_hash2 = md5->avxc + c;
    md5->avx_hash3 = md5->avxd + d;  	
}

void md5_bigendian(MD5 *md5, uchar final0[], uchar final1[], uchar final2[], uchar final3[]){
    
    __m128i q,r,s,t;
    uint m[4],n[4],o[4],p[4];

    q = md5->avx_hash0;
    r = md5->avx_hash1;
    s = md5->avx_hash2;
    t = md5->avx_hash3;
    
    int* res0 = (int*)&q;
  	int* res1 = (int*)&r;
  	int* res2 = (int*)&s;
  	int* res3 = (int*)&t;


  	printf("q =  %x %x %x %x\n",res0[0],res0[1],res0[2],res0[3]);
  	printf("r =  %x %x %x %x\n",res1[0],res1[1],res1[2],res1[3]);
	printf("s =  %x %x %x %x\n",res2[0],res2[1],res2[2],res2[3]);
	printf("t =  %x %x %x %x\n",res3[0],res3[1],res3[2],res3[3]);
	
	// Separate the AVX functions and pull out the parts that you want
	// Message 0
    m[0] = res0[0];
    n[0] = res0[0];
    o[0] = res0[0];
    p[0] = res0[0];

    m[1] = res1[0];
    n[1] = res1[0];
    o[1] = res1[0];
    p[1] = res1[0];

    m[2] = res2[0];
    n[2] = res2[0];
    o[2] = res2[0];
    p[2] = res2[0];

    m[3] = res3[0];
    n[3] = res3[0];
    o[3] = res3[0];
    p[3] = res3[0];

    final0[0] = (m[0] & 0x000000ff);
    final0[1] = ((n[0] >> 8) & 0x0000ff);
    final0[2] = ((o[0] >> 16) & 0x00ff);
    final0[3] = ((p[0] >> 24) & 0xff);
    final0[4] = (m[1] & 0x000000ff);
    final0[5] = ((n[1] >> 8) & 0x0000ff);
    final0[6] = ((o[1] >> 16) & 0x00ff);
    final0[7] = ((p[1] >> 24) & 0xff);
    final0[8] = (m[2] & 0x000000ff);
    final0[9] = ((n[2] >> 8) & 0x0000ff);
    final0[10] = ((o[2] >> 16) & 0x00ff);
    final0[11] = ((p[2] >> 24) & 0xff);
    final0[12] = (m[3] & 0x000000ff);
    final0[13] = ((n[3] >> 8) & 0x0000ff);
    final0[14] = ((o[3] >> 16) & 0x00ff);
    final0[15] = ((p[3] >> 24) & 0xff);

    // Message 1
    m[0] = res0[1];
    n[0] = res0[1];
    o[0] = res0[1];
    p[0] = res0[1];

    m[1] = res1[1];
    n[1] = res1[1];
    o[1] = res1[1];
    p[1] = res1[1];

    m[2] = res2[1];
    n[2] = res2[1];
    o[2] = res2[1];
    p[2] = res2[1];

    m[3] = res3[1];
    n[3] = res3[1];
    o[3] = res3[1];
    p[3] = res3[1];

    final1[0] = (m[0] & 0x000000ff);
    final1[1] = ((n[0] >> 8) & 0x0000ff);
    final1[2] = ((o[0] >> 16) & 0x00ff);
    final1[3] = ((p[0] >> 24) & 0xff);
    final1[4] = (m[1] & 0x000000ff);
    final1[5] = ((n[1] >> 8) & 0x0000ff);
    final1[6] = ((o[1] >> 16) & 0x00ff);
    final1[7] = ((p[1] >> 24) & 0xff);
    final1[8] = (m[2] & 0x000000ff);
    final1[9] = ((n[2] >> 8) & 0x0000ff);
    final1[10] = ((o[2] >> 16) & 0x00ff);
    final1[11] = ((p[2] >> 24) & 0xff);
    final1[12] = (m[3] & 0x000000ff);
    final1[13] = ((n[3] >> 8) & 0x0000ff);
    final1[14] = ((o[3] >> 16) & 0x00ff);
    final1[15] = ((p[3] >> 24) & 0xff);

    // Message 2
    m[0] = res0[2];
    n[0] = res0[2];
    o[0] = res0[2];
    p[0] = res0[2];

    m[1] = res1[2];
    n[1] = res1[2];
    o[1] = res1[2];
    p[1] = res1[2];

    m[2] = res2[2];
    n[2] = res2[2];
    o[2] = res2[2];
    p[2] = res2[2];

    m[3] = res3[2];
    n[3] = res3[2];
    o[3] = res3[2];
    p[3] = res3[2];

    final2[0] = (m[0] & 0x000000ff);
    final2[1] = ((n[0] >> 8) & 0x0000ff);
    final2[2] = ((o[0] >> 16) & 0x00ff);
    final2[3] = ((p[0] >> 24) & 0xff);
    final2[4] = (m[1] & 0x000000ff);
    final2[5] = ((n[1] >> 8) & 0x0000ff);
    final2[6] = ((o[1] >> 16) & 0x00ff);
    final2[7] = ((p[1] >> 24) & 0xff);
    final2[8] = (m[2] & 0x000000ff);
    final2[9] = ((n[2] >> 8) & 0x0000ff);
    final2[10] = ((o[2] >> 16) & 0x00ff);
    final2[11] = ((p[2] >> 24) & 0xff);
    final2[12] = (m[3] & 0x000000ff);
    final2[13] = ((n[3] >> 8) & 0x0000ff);
    final2[14] = ((o[3] >> 16) & 0x00ff);
    final2[15] = ((p[3] >> 24) & 0xff);

    // Message 3
    m[0] = res0[3];
    n[0] = res0[3];
    o[0] = res0[3];
    p[0] = res0[3];

    m[1] = res1[3];
    n[1] = res1[3];
    o[1] = res1[3];
    p[1] = res1[3];

    m[2] = res2[3];
    n[2] = res2[3];
    o[2] = res2[3];
    p[2] = res2[3];

    m[3] = res3[3];
    n[3] = res3[3];
    o[3] = res3[3];
    p[3] = res3[3];

    final3[0] = (m[0] & 0x000000ff);
    final3[1] = ((n[0] >> 8) & 0x0000ff);
    final3[2] = ((o[0] >> 16) & 0x00ff);
    final3[3] = ((p[0] >> 24) & 0xff);
    final3[4] = (m[1] & 0x000000ff);
    final3[5] = ((n[1] >> 8) & 0x0000ff);
    final3[6] = ((o[1] >> 16) & 0x00ff);
    final3[7] = ((p[1] >> 24) & 0xff);
    final3[8] = (m[2] & 0x000000ff);
    final3[9] = ((n[2] >> 8) & 0x0000ff);
    final3[10] = ((o[2] >> 16) & 0x00ff);
    final3[11] = ((p[2] >> 24) & 0xff);
    final3[12] = (m[3] & 0x000000ff);
    final3[13] = ((n[3] >> 8) & 0x0000ff);
    final3[14] = ((o[3] >> 16) & 0x00ff);
    final3[15] = ((p[3] >> 24) & 0xff);
    
}






