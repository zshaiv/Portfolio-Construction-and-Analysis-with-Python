import ctypes
import time
clibrary = ctypes.CDLL("AAPL.so")
start_time = time.time()

clibrary.main()
print("Process finished --- %s seconds ---" % (time.time() - start_time))

