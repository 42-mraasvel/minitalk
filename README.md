**STEPS**

	- make
	- run server (./server)
	- open new terminal
	- run client [SERVER_PID] [DATA_TO_SEND]

**Generate big file to test**

	# MAC:

		LC_CTYPE=C tr -dc "A-Za-z 0-9" < /dev/urandom | fold -w100|head -n 10 > bigfile.txt

	# LINUX:

		tr -dc "A-Za-z 0-9" < /dev/urandom | fold -w100|head -n 10 > bigfile.txt

**UNICODE / EMOJIS**

	https://unicode.org/emoji/charts/full-emoji-list.html
	😀😃😇🥰😍🥲
