python3 index.py $1 $2
cd ./output/images
read  -n 1 -p "Download (y/n):" downloadconfirmation
if [ $downloadconfirmation == "y" ]; then
    echo "Downloading... "
    for file in ../text_files/*.txt
    do
        wget -i $file &
    done
else
    echo "Not downloading..."
fi
