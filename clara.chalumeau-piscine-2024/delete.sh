while IFS='' read -r line; do
    git tag -d $line
done < "tag.txt"
