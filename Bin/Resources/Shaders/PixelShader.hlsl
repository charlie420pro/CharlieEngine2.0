struct PS_INPUT
{
	float2 texCoord : TEXCOORD;
};

float4 PSMain() : SV_Target
{
	return float4(1.0f,1.0f,0.3f,1.0f);
}