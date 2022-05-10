function clearbits(pixval){
	var x = Math.floor(pixval/16) * 16;
	return x;
}

function chop2hide(image){
	for(var px of image.values()){
		px.setRead(clearbits(px.getRed()));
		px.setGreen(clearbits(px.getGreen()));
		px.setBlue(clearbits(px.getBlue()));
	}
	return image;
}