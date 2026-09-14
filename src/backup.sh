#!/bin/bash
echo "Backup started"
#rm -rf backup/
DATA_DIR=data/
AJT_DIR=AJT/
BACKUP=backup/
if [ ! -d $DATA_DIR ]; then
	echo "$DATA_DATA DIR does exist."
	echo "Backup interrupted"
	exit -1
fi
if [ ! -d $AJT_DIR ]; then
	echo "$AJT_DATA DIR does not exist!"
	echo "Backup interrupted"
	exit -1
fi
if [ ! -d "$BACKUP" ]; then
	mkdir ${BACKUP}
fi
cd "${BACKUP}"
timestamp=$(date '+%Y%m%d_%H%M%S')
extension=".zip"
fileName="${timestamp}${extension}"
DATA_DEST="${timestamp}"
AJT_DEST="AJT_${timestamp}"

cp -r "../${DATA_DIR}" ${DATA_DEST}
zip -r ${fileName} ${DATA_DEST}
rm -rf ${DATA_DEST}
echo "Root 'data' backup: $fileName"
cp -r "../${AJT_DIR}" ${AJT_DEST}
zip -r "AJT_${fileName}" ${AJT_DEST}
rm -rf ${AJT_DEST}
echo "AJT 'data' backup: AJT_${fileName}"

echo "Backup finished"
exit 0
