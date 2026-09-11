#!/bin/bash
echo "Backup started"
DIR=data/
BACKUP=backup/
if [ ! -d "$DIR" ]; then
  echo "$DIR does exist."
  echo "Backup interrupted"
  exit -1
fi
if [ ! -d "$BACKUP" ]; then
	mkdir ${BACKUP}
fi
cd "${BACKUP}"
timestamp=$(date '+%Y-%m-%d_%H:%M:%S')
extension=".zip"
fileName="${timestamp}${extension}"
echo "file name is: $fileName"
DEST="${timestamp}"
cp -r "../${DIR}" ${DEST}
zip -r "${fileName}" "${timestamp}"
rm -rf "${timestamp}"
echo "Backup finished"
exit 0
