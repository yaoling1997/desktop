while true; do
./make
./1
./2
diff -b 1.out 2.out -q
if [ $? -eq 0 ]; then echo Right!
else {
	echo Wrong!
	break
}
fi
done
