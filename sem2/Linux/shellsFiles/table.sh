
echo "Enter number: "
read n

echo "Table of $n"

i=1

while [ "$i" -le 10 ]
do
ans=$((i * n))
echo "$ans"
i=$((i + 1))
done