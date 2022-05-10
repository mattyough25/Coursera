function shift(image){
	for(var px of image.values()){
		px.setRead(px.getRed()/16);
		px.setGreen(px.getGreen()/16);
		px.setBlue(px.getBlue()/16);
	}
	return image;
}