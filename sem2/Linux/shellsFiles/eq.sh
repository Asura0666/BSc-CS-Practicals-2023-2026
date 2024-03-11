
echo "Enter 1st number: "
read n1

echo "Enter 2nd number: "
read n2

if [ "$n1" -eq "$n2" ]
then 
echo "Numbers are equal ($n1 == $n2)"
else 
echo "Numbers are not equal ($n1 != $n2)"
fi

