while true; do
./make
./1
./2
diff -b 1.out 2.out
if [ $? -eq 0 ]; then echo right!
else {
	echo wrong!
	break
}
fi
done
