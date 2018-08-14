while true; do
./make
./1
./check
diff -b check.out ok.out
if [ $? -eq 0 ]; then echo right!
else {
	echo wrong!
	break
}
fi
done
