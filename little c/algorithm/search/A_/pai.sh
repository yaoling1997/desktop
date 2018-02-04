while true; do
./make
./2
./3
diff -b 2.out 3.out
if [ $? -eq 0 ]; then echo right
else {
	echo wrong
	break
}
fi
done
