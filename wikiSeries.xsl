<?xml version='1.0' ?> 
<xsl:stylesheet version="1.1" 
xmlns:xsl="http://www.w3.org/1999/XSL/Transform"> 
  <xsl:template match="/"> 
   <HTML> 
    <BODY> 
     <B> Wiki Series</B> 
     <BR/> 
     <BR/> 
     <TABLE> 
	<xsl:apply-templates select="WIKISERIES/SERIE"/>

<!--      <xsl:for-each  select="CLASE[@CURSO='5']/ALUMNO[NOTA&lt;5]"> 
      <xsl:sort order="ascending" select="APELLIDOS"/> 
       <TR> 
        <TD><xsl:value-of select="APELLIDOS"/>, <xsl:value-of select="NOMBRE"/></TD> 
        <TD><B><xsl:value-of select="NOTA"/></B></TD> 
        <BR></BR> 
       </TR> 
      </xsl:for-each>  -->


     </TABLE> 
    </BODY> 
   </HTML> 
  </xsl:template> 

<xsl:template match="SERIE">
      <TR> 
        <H3>Personajes Principales <xsl:value-of select="PERSONAJES/PRINCIPALES"/> </H3>
        <BR></BR> 
	<H3>Personajes Secundarios <xsl:value-of select="PERSONAJES/SECUNDARIOS"/></H3> 
      </TR> 
</xsl:template>

 </xsl:stylesheet> 


