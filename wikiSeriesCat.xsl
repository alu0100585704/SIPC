<?xml version='1.0' ?> 
<xsl:stylesheet version="1.1" 
xmlns:xsl="http://www.w3.org/1999/XSL/Transform"> 
  <xsl:template match="/"> 
   <HTML> 
    <BODY> 

	
	<xsl:apply-templates select="WIKISERIES/CATEGORIA"/>


    </BODY> 
   </HTML> 
  </xsl:template> 

<xsl:template match="CATEGORIA">
	<div style="display:inline;">

        <H3><xsl:value-of select="@NOMBRE"/> </H3>
	<xsl:element name="img">
		<xsl:attribute name="src">
			<xsl:value-of select="@RUTAIMAGEN"/>
		</xsl:attribute>

		<xsl:attribute name="width">
			10%
		</xsl:attribute>

		<xsl:attribute name="height">
			10%
		</xsl:attribute>

	</xsl:element>	

	
	</div>

</xsl:template>

 </xsl:stylesheet> 

