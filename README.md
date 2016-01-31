# hashing-optimization-
MD5 Implementation that has been Optimized in several ways. Hardware Security Assignment.

PROJECT I: FAST IMPLEMENTATIONS OF MD5/SHA1

Problem 1. Fast software implementation of the MD5/SHA1 message digest algorithm. You are
to implement, in C, a loop unrolled version of the algorithm for password cracking purposes.
Your password cracker will utilise the AVX extensions to compute multiple hashes in parallel.
You will need to cite an example of how you use AVX-specic extensions (i.e. functionality
that is not found in the SSE extensions; this cannot just be the use of 256-bit registers).
In addition, you must propose and verify the benets of two architecture-aware/instruction-
level optimisations of your choosing/devising; the goal of the optimisations is to increase the
password hashing rate. Your grade will be determined, in part, on the originality, analysis,
and ecacy of the optimisations you choose. The maximum password length we will consider
is 10 characters, upper/lowercase alpha, no salting. Examples of how to generate candidates
can be found in the source code posted on the wiki; e.g. bla.zip and md5-amd64.tar.bz2. The
password you are to crack will posted to the wiki during the week of February the eighth.
To benchmark your code|i.e. determine how many passwords per second it can hash|you'll
need to time how long it takes to hash every possible password of length six, assuming a
lowercase, alphabetic character set (see below). You will submit four versions of your code:
an AVX implementation without optimisations (baseline), a separate baseline version with
each optimisation, and a nal version that includes both optimisations. You are attempting
to demonstrate the improvement of each optimisation individually, as well as in combination.
While you may look at previous student projects for optimisations to further improve your
own implementation, you must propose an additional optimisation not found in their work.
To ease the workload, you need to work in groups of two.

Problem 2. Hardware implementation of the MD5/SHA1 message digest algorithm. Implement the
algorithm in either a) an FPGA or b) GPU. The FPGA implementation must be completed
structurally; state machines for control may be done behaviourally. To benchmark an FPGA
implementation you are only required to use the throughput calculation given in Lecture
IV. You may assume that the message to be hashed is padded and has the correct length
appended and that it resides in memory (to verify your implementation you'll have to have a
long test message in memory and show that it is hashed correctly). Extra credit/leniency for
a pipelined implementation. A GPU implementation should be benchmarked in the same way
as the software implementation described above.

Problem 3. Benchmarking Your code will be benchmarked (using the procedure outlined above)
on a GNU/Linux distribution with kernel 3.2.0-48 and GCC version 4.6.3 (Ubuntu 12.04). In
order to evaluate your code, provide a Makefile that compiles the following versions of your
implementation (naming convention to follow in parenthesis):
(a) standard AVX implementation (pwck base)
(b) standard AVX implementation w/optimisation X and -O0 (pwckX O0, where X is the
optimsation number)
(c) standard AVX implementation w/optimisation X and -O1 and -fomit-frame-pointer
(pwckX O1)
ECE 5760/6760 Project I: Fast Implementations1of MD5/SHA1 Spring 2016
(d) standard AVX implementation w/optimisation X and -O2 and -fomit-frame-pointer
(pwckX O2)
(e) standard AVX implementation w/optimisation X and -O3 and -fomit-frame-pointer
(pwckX O3)
(f) standard AVX implementation w/both optimsations and each combination of above 
ags
(follow the same naming structure but omit the X).
You may also include 
ags necessary to enable your optimisations in the above. Your report
should include a table with these benchmarks. Proper benchmarking requires that we compare
the hash of the candidate with the hash of an actual (unknown) password. Use the hash of
the last candidate in the search space (zzzzzz ) as the hash of the unknown password for
benchmarking purposes.

Problem 4. Reporting requirements. A report template will be provided on the wiki, but, in
general, your report should include: Introduction, related/background work (information nec-
essary to understand the optimization techniques you relied on, etc.), an explanation of your
implementation (e.g. how did you use AVX; divide by hardware and software), and an analy-
sis/explication of your optimisations (i.e. a justication of your optimisations).
My grading criteria will include:
1. Veried software implementation by nding pre-image of provided hash
2. Veried hardware implementation by showing output
3. Calculated throughput of hardware implementation
4. Discussed software optimisations of choice and demonstrated their worth (even if slight)
5. Justication and originality of optimisations
6. Details on FPGA/GPU target
7. Informative, organised, and cohesive report
