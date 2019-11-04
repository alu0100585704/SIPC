<?xml version='1.0' ?> 
<xsl:stylesheet version="1.1" 
xmlns:xsl="http://www.w3.org/1999/XSL/Transform"> 
  <xsl:template match="/"> 
   <HTML> 
    <BODY> 


	<xsl:apply-templates select="GUATACA/CATEGORIA"/>


    </BODY> 
   </HTML> 
  </xsl:template> 

<xsl:template match="CATEGORIA">

<div style="float:fixed;width:15%;position:relative">
	
<xsl:element name="a">
	<xsl:attribute name="href">
			<xsl:value-of select="@WEB"/>
	</xsl:attribute>

	<xsl:element name="img">
		<xsl:attribute name="src">
			<xsl:value-of select="@IMAGEN"/>
		</xsl:attribute>

		<xsl:attribute name="width">
			100%
		</xsl:attribute>

	</xsl:element>	
	
</xsl:element>

 

	
</div>

</xsl:template>

 </xsl:stylesheet> 
