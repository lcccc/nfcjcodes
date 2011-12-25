import urllib
import time
url = 'http://www.hacker.org/challenge/chal.php?id=138&name=liuchang&password=757695453&';
for i in range(1000):
	surl  = url + "answer="+str(i);
	print surl
	repon = urllib.urlopen(surl).read()
	print repon
	print '+++++++++++++++++++++++++++++++++'
	
	if( repon.find("incorrect")==-1):
		print "ans is %d"%i
		break;
	time.sleep(60)

